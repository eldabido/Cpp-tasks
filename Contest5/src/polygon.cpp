#include <iostream>
#include "../ishape.h"
#include "../point.h"
#include "../polygon.h"
#include "../segment.h"
#include "cmath"
#include "../vector.h"
#include "../ray.h"
#include "../line.h"

// реализация Polygon.

geometry::Polygon::Polygon(std::vector<Point> verts) {
  size_ = verts.size();
  vertices_.reserve(size_);
  for (int i = 0; i < static_cast<int>(size_); ++i) {
    vertices_.push_back(verts[i]);
  }
}

geometry::Polygon::~Polygon() {
  vertices_.clear();
}

geometry::IShape& geometry::Polygon::Move(const Vector& vect) {
  for (int i = 0; i < static_cast<int>(size_); ++i) {
    vertices_[i].SetX(vect.GetX());
    vertices_[i].SetY(vect.GetY());
  }
  return *this;
}

bool geometry::Polygon::ContainsPoint(const Point& point) const {
  // Пускаем луч и прямую из точки в соответствии с презентацией.
  Ray r = Ray(point, Point(point.GetX() + 1, point.GetY() + 1));
  Line l = Line(point, Point(point.GetX() + 1, point.GetY() + 1));
  int count = 0;
  bool result;
  for (int i = 0; i < static_cast<int>(size_) - 1; ++i) {
    // Если сторона содержит точку, то можно сразу возвращать true.
    if ((result = (Segment(vertices_[i], vertices_[i + 1])).ContainsPoint(point))) {
      return result;
    }
    // Смотрим, пересекает ли луч сторону.
    if (r.CrossesSegment(Segment(vertices_[i], vertices_[i + 1]))) {
      ++count;
      // Если сторона лежит на луче, то не учитываем.
      if (l.ContainsPoint(vertices_[i]) && l.ContainsPoint(vertices_[i + 1])) {
        --count;
        // Если пересекает вершину, то в соответствии с презентацией считаем.
      } else if (i >= 1 && r.ContainsPoint(vertices_[i])) {
        // Векторные произведения, чтоб смотреть, как расположены стороны относительно луча.
        // Если они разного знака, то они по разные стороны.
        int s1 = (vertices_[i - 1].GetY() - vertices_[i].GetY()) * r.GetVect().GetX() -
                 (vertices_[i - 1].GetX() - vertices_[i].GetX()) * r.GetVect().GetY();
        int s2 = (vertices_[i + 1].GetY() - vertices_[i].GetY()) * r.GetVect().GetX() -
                 (vertices_[i + 1].GetX() - vertices_[i].GetX()) * r.GetVect().GetY();
        if (s1 * s2 < 0) {
          --count;
        }
      }
    }
  }
  // Отдельно смотрим последнюю сторону.
  if (r.CrossesSegment(Segment(vertices_[size_ - 1], vertices_[0]))) {
    if ((result = (Segment(vertices_[size_ - 1], vertices_[0])).ContainsPoint(point))) {
      return result;
    }
    ++count;
    if (l.ContainsPoint(vertices_[size_ - 1]) && l.ContainsPoint(vertices_[0])) {
      --count;
    } else if (r.ContainsPoint(vertices_[size_ - 1])) {
      int sc1 = (vertices_[size_ - 2].GetY() - vertices_[size_ - 1].GetY()) * r.GetVect().GetX() -
                (vertices_[size_ - 2].GetX() - vertices_[size_ - 1].GetX()) * r.GetVect().GetY();
      int sc2 = (vertices_[0].GetY() - vertices_[size_ - 1].GetY()) * r.GetVect().GetX() -
                (vertices_[0].GetX() - vertices_[size_ - 1].GetX()) * r.GetVect().GetY();
      if (sc1 * sc2 < 0) {
        --count;
      }
    }
  }
  // Если счетчик нечетный, то точка внутри.
  return count % 2 != 0 ? 1 : 0;
}

bool geometry::Polygon::CrossesSegment(const Segment& segment) const {
  // Здесь просто поочередно проверяем пересечение каждой стороны и сегмента.
  bool result = false;
  for (int i = 0; i < static_cast<int>(size_) - 1; ++i) {
    if ((result = segment.CrossesSegment(Segment(vertices_[i], vertices_[i + 1])))) {
      return result;
    }
  }
  if (((result = segment.CrossesSegment(Segment(vertices_[0], vertices_[size_ - 1]))))) {
    return result;
  }
  return result;
}

std::unique_ptr<geometry::IShape> geometry::Polygon::Clone() const {
  return std::make_unique<Polygon>(*this);
}

std::string geometry::Polygon::ToString() const {
  std::string str = "Polygon(";
  for (int i = 0; i < static_cast<int>(size_) - 1; ++i) {
    str += vertices_[i].ToString();
    str += ", ";
  }
  str += vertices_[size_ - 1].ToString();
  str += ")";
  return str;
}