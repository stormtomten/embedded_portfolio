#include <bitset>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <int1> <int2>" << std::endl;
    return 1;
  }
  int a = std::atoi(argv[1]);
  int b = std::atoi(argv[2]);
  std::cout << "Before: " << a << " " << b << std::endl;

  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
  std::cout << "After: " << a << " " << b << std::endl;
}
