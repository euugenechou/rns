#include "rns.h"

int main(void) {
  RN n = 24;
  std::cout << "n = " << n << std::endl;

  n += 1;
  std::cout << "n = " << n << std::endl;

  n -= 8;
  std::cout << "n = " << n << std::endl;

  n *= 2;
  std::cout << "n = " << n << std::endl;

  n %= 10;
  std::cout << "n = " << n << std::endl;

  n /= 2;
  std::cout << "n = " << n << std::endl;

  n = 9576643908267;
  std::cout << "n = " << n << std::endl;

  return 0;
}
