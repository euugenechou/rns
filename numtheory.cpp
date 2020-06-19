#include "numtheory.h"

// Code from Rosetta Code.

int64_t mod(int64_t a, int64_t b) {
  int64_t rem = a % b;

  while (rem < 0) {
    rem += b;
  }

  return rem;
}

int64_t inv(int64_t a, int64_t b) {
  int64_t b0 = b, t, q;
  int64_t x0 = 0, x1 = 1;

  if (b == 1) {
    return 1;
  }

  while (a > 1) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }

  if (x1 < 0) {
    x1 += b0;
  }

  return x1;
}

int64_t CRT(const std::vector<int8_t>& n, const std::vector<int8_t>& a) {
  int64_t p, prod = 1, sum = 0;

  for (size_t i = 0; i < n.size(); i += 1) {
    prod *= n[i];
  }


  for (size_t i = 0; i < n.size(); i += 1) {
    p = prod / n[i];
    sum += a[i] * inv(p, n[i]) * p;
  }

  return sum % prod;
}
