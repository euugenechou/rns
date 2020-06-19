#ifndef __NUMTHEORY_H__
#define __NUMTHEORY_H__

#include <cstdint>
#include <vector>

int64_t mod(int64_t a, int64_t b);

int64_t inverse(int64_t n, int64_t p);

int64_t CRT(const std::vector<int8_t>& a, const std::vector<int8_t>& b);

#endif
