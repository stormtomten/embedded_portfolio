#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <int1>" << std::endl;
    return 1;
  }
  int a = std::atoi(argv[1]);
  std::cout << "Input: " << a << std::endl;
  std::cout << a << " is " << ([](int a) {
    return (((a & (a - 1)) == 0) && (a > 0)) ? "" : "not ";
  })(a) << "a power of 2"
            << std::endl;
}
