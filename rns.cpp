#include "rns.h"
#include "numtheory.h"
#include <algorithm>
#include <utility>

std::vector<int8_t> RN::m = { 37, 73, 103, 47, 79, 127 };
int64_t RN::M = 126947;
int64_t RN::M_ = 75438127;
int64_t RN::MM_ = RN::M * RN::M_; // Only 9576643908269.

RN::RN() {
  for (size_t i = 0; i < m.size(); i += 1) {
    x.push_back(0);
  }
}

RN::RN(int64_t n) {
  assert(0 <= n && n < MM_);

  for (const auto& it : m) {
    x.push_back(n % it);
  }
}

RN::RN(const RN& n) {
  for (auto it : n.x) {
    x.push_back(it);
  }
}

RN& RN::operator=(RN rhs) {
  std::swap(x, rhs.x);
  return *this;
}

RN& RN::operator+=(const RN& rhs) {
  for (size_t i = 0; i < m.size(); i += 1) {
    x[i] = mod(x[i] + rhs.x[i], m[i]);
  }

  return *this;
}

RN RN::operator+(const RN& rhs) const {
  return RN(*this) += rhs;
}

RN& RN::operator-=(const RN& rhs) {
  for (size_t i = 0; i < m.size(); i += 1) {
    x[i] = mod(x[i] - rhs.x[i], m[i]);
  }

  return *this;
}

RN RN::operator-(const RN& rhs) const {
  return RN(*this) -= rhs;
}

RN& RN::operator*=(const RN& rhs) {
  for (size_t i = 0; i < m.size(); i += 1) {
    x[i] = mod(x[i] * rhs.x[i], m[i]);
  }

  return *this;
}

RN RN::operator*(const RN& rhs) const {
  return RN(*this) *= rhs;
}


int64_t RN::recip(int64_t Y) {
  assert(1 <= Y && Y < M);

  int64_t Z1 = 0;
  int64_t Z2 = 2;

  while (Z1 != Z2) {
    Z1 = Z2;
    Z2 = Z1 * (2 * M - Y * Z1) / M;
  }

  return M - Y * Z2 < Y ? Z2 : Z2 + 1;
}

std::tuple<int64_t, int64_t> RN::divrem(const RN& a, const RN& b) {
  int64_t X = CRT(m, a.x);
  int64_t Y = CRT(m, b.x);

  assert(0 <= X && X < M && 1 <= Y && Y < M);

  int64_t Q = X * recip(Y) / M;
  int64_t R = X - Q * Y;

  return R < Y ? std::make_tuple(Q, R) : std::make_tuple(Q + 1, R - Y);
}

RN& RN::operator/=(const RN& rhs) {
  RN rem = RN(std::get<0>(divrem(*this, rhs)));
  std::swap(x, rem.x);
  return *this;
}

RN RN::operator/(const RN& rhs) const {
  return RN(*this) /= rhs;
}

RN& RN::operator%=(const RN& rhs) {
  RN rem = RN(std::get<1>(divrem(*this, rhs)));
  std::swap(x, rem.x);
  return *this;
}

RN RN::operator%(const RN& rhs) const {
  return RN(*this) %= rhs;
}

std::ostream& operator<<(std::ostream& os, const RN& n) {
  os << CRT(RN::m, n.x);
  return os;
}
