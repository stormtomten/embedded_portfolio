#include <bitset>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <int1> <int2>" << std::endl;
    return 1;
  }
  int a = std::atoi(argv[1]);
  int b = std::atoi(argv[2]);
  std::cout << "Input: num = " << a << " (" << std::bitset<4>(a)
            << " in binary), k = " << b << std::endl;

  a ^= (1 << b);
  std::cout << "Output:" << a << " (" << std::bitset<4>(a) << " in binary)"
            << std::endl;
}
