#ifndef H_RATIONAL
#define H_RATIONAL

#include <cmath>
#include <iostream>
#include <numeric>

class RationalDivisionByZero: std::exception {
};

class Rational {
private:
  int numerator_;
  int denominator_;
public:
  Rational();
  Rational(int num); //NOLINT
  Rational(int num, int denom);
  int GetNumerator() const;
  int GetDenominator() const;
  void SetNumerator(int num);
  void SetDenominator(int denom);
  Rational operator+(const Rational& second) const;
  Rational operator-(const Rational& second) const;
  Rational operator*(const Rational& second) const;
  Rational operator/(const Rational& second) const;
  Rational& operator+=(const Rational& second);
  Rational& operator-=(const Rational& second);
  Rational& operator*=(const Rational& second);
  Rational& operator/=(const Rational& second);
  Rational operator-() const;
  Rational operator+() const;
  Rational& operator++();
  Rational operator++(int);
  Rational& operator--();
  Rational operator--(int);
  friend std::ostream& operator<<(std::ostream& out, const Rational& value);
  friend std::istream& operator>>(std::istream& input, Rational& value);
};

bool operator==(const Rational& first, const Rational& second);
bool operator!=(const Rational& first, const Rational& second);
bool operator<(const Rational& first, const Rational& second);
bool operator>(const Rational& first, const Rational& second);
bool operator<=(const Rational& first, const Rational& second);
bool operator>=(const Rational& first, const Rational& second);
#endif