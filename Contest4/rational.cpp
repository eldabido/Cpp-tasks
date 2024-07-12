#include "rational.h"

Rational::Rational() {
  numerator_ = 0;
  denominator_ = 1;
}

Rational::Rational(int num) {
  numerator_ = num;
  denominator_ = 1;
}

Rational::Rational(int num, int denom) {
  if (denom < 0) {
    num = -num;
    denom = -denom;
  } else if (denom == 0) {
    throw RationalDivisionByZero{};
  }
  int gcd = std::gcd(num, denom);
  numerator_ = num / gcd;
  denominator_ = denom / gcd;
}

int Rational::GetNumerator() const {
  return numerator_;
}

int Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(int num) {
  int gcd = std::gcd(num, denominator_);
  numerator_ = num / gcd;
  denominator_ = denominator_ / gcd;
}

void Rational::SetDenominator(int denom) {
  if (denom < 0) {
    numerator_ = -numerator_;
    denom = -denom;
  } else if (denom == 0) {
    throw RationalDivisionByZero{};
  }
  int gcd = std::gcd(numerator_, denom);
  numerator_ = numerator_ / gcd;
  denominator_ = denom / gcd;
}

// Бинарные арифметические операции.
Rational Rational::operator+(const Rational& second) const {
  int first = numerator_ * second.denominator_ + second.numerator_ * denominator_;
  int sec = denominator_ * second.denominator_;
  int gcd = std::gcd(first, sec);
  return { first / gcd, sec / gcd };
}

Rational Rational::operator-(const Rational& second) const {
  int first = numerator_ * second.denominator_ - second.numerator_ * denominator_;
  int sec = denominator_ * second.denominator_;
  int gcd = std::gcd(first, sec);
  return  { first / gcd, sec / gcd };
}

Rational Rational::operator*(const Rational& second) const {
  int first = numerator_ * second.numerator_;
  int sec = denominator_ * second.denominator_;
  int gcd = std::gcd(first, sec);
  return { first / gcd, sec / gcd };
}

Rational Rational::operator/(const Rational& second) const {
  int first = numerator_ * second.denominator_;
  int sec = denominator_ * second.numerator_;
  int gcd = std::gcd(first, sec);
  return { first / gcd, sec / gcd };
}

//  Их присваивающие версии.
Rational& Rational::operator+=(const Rational& second) {
  *this = *this + second;
  return *this;
}

Rational& Rational::operator-=(const Rational& second) {
  *this = *this - second;
  return *this;
}

Rational& Rational::operator*=(const Rational& second) {
  *this = *this * second;
  return *this;
}

Rational& Rational::operator/=(const Rational& second) {
  *this = *this / second;
  return *this;
}

// Унарные операции.
Rational Rational::operator-() const {
  return { -numerator_, denominator_ };
}

Rational Rational::operator+() const {
  return { numerator_, denominator_ };
}

// Префиксные и постфиксные инкременты и декременты.
Rational& Rational::operator++() {
  numerator_ += denominator_;
  return *this;
}

Rational Rational::operator++(int) {
  auto old = *this;
  numerator_ += denominator_;
  return old;
}

Rational& Rational::operator--() {
  numerator_ -= denominator_;
  return *this;
}

Rational Rational::operator--(int) {
  auto old = *this;
  numerator_ -= denominator_;
  return old;
}

// Операции сравнения.
bool operator==(const Rational& first, const Rational& second)  {
  return (first.GetNumerator() == second.GetNumerator()) && (first.GetDenominator() == second.GetDenominator());
}

bool operator!=(const Rational& first, const Rational& second) {
  return (first.GetNumerator() != second.GetNumerator()) || (first.GetDenominator() != second.GetDenominator());
}

bool operator<(const Rational& first, const Rational& second) {
  return first.GetNumerator() * second.GetDenominator() < first.GetDenominator() * second.GetNumerator();
}

bool operator>(const Rational& first, const Rational& second) {
  return first.GetNumerator() * second.GetDenominator() > first.GetDenominator() * second.GetNumerator();
}

bool operator<=(const Rational& first, const Rational& second) {
  return first.GetNumerator() * second.GetDenominator() <= first.GetDenominator() * second.GetNumerator();
}

bool operator>=(const Rational& first, const Rational& second) {
  return first.GetNumerator() * second.GetDenominator() >= first.GetDenominator() * second.GetNumerator();
}

// Операции ввода и вывода в поток.
std::ostream& operator<<(std::ostream& out, const Rational& value) {
  if (value.denominator_ == 1) {
    out << value.numerator_;
  } else {
    out << value.numerator_ << "/" << value.denominator_;
  }
  return out;
}

std::istream& operator>>(std::istream& input, Rational& value) {
  int num = 0;
  int denom = 0;
  char slash = ' ';
  input >> num;
  if (input.peek() == '/') {
    input >> slash >> denom;
    value = Rational(num, denom);
  } else {
    value = Rational(num);
  }
  return input;
}