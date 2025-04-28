#include "hamming.h"
#include <bitset>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <int1>" << std::endl;
    return 1;
  }
  int a = std::atoi(argv[1]);
  int count = 0;

  std::cout << "Talet " << a << "   " << std::bitset<8>(a);

  while (a > 0) {
    if (a & 0b1) {
      count++;
    }
    a = a >> 1;
  }

  std::cout << " inehåller " << count << " ettor." << std::endl;
  return 0;
}
