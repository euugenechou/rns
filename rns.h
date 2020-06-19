#ifndef __RNS_H__
#define __RNS_H__

#include <cstdint>
#include <iostream>
#include <vector>
#include <tuple>

class RN {
  private:
    static int64_t M;
    static int64_t M_;
    static int64_t MM_;
    static std::vector<int8_t> m;

    static int64_t recip(int64_t Y);
    static std::tuple<int64_t, int64_t> divrem(const RN& a, const RN& b);

    std::vector<int8_t> x;

  public:
    RN();
    RN(int64_t n);
    RN(const RN& n);

    RN& operator=(RN rhs);

    RN& operator+=(const RN& rhs);
    RN operator+(const RN& rhs) const;

    RN& operator-=(const RN& rhs);
    RN operator-(const RN& rhs) const;

    RN& operator*=(const RN& rhs);
    RN operator*(const RN& rhs) const;

    RN& operator/=(const RN& rhs);
    RN operator/(const RN& rhs) const;

    RN& operator%=(const RN& rhs);
    RN operator%(const RN& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const RN& n);
};

template<class T>
inline RN operator+(const T& lhs, const RN& rhs) {
  return RN(lhs) += rhs;
}

template<class T>
inline RN operator-(const T& lhs, const RN& rhs) {
  return RN(lhs) -= rhs;
}

template<class T>
inline RN operator*(const T& lhs, const RN& rhs) {
  return RN(lhs) *= rhs;
}

template<class T>
inline RN operator/(const T& lhs, const RN& rhs) {
  return RN(lhs) /= rhs;
}

template<class T>
inline RN operator%(const T& lhs, const RN& rhs) {
  return RN(lhs) %= rhs;
}

#endif
