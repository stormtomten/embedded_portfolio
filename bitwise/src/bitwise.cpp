#include <bitset>
#include <iostream>

void swap_int(int &a, int &b) {
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
}
bool powtwo(int a) {
  if (((a & (a - 1)) == 0) && (a > 0)) {
    return true;
  } else {
    return false;
  }
}
int hamming(int a) {
  int count = 0;
  while (a > 0) {
    if (a & 0b1) {
      count++;
    }
    a = a >> 1;
  }
  return count;
}

int kbit(int a, int b) { return ((a >> b) & 1); }
int kflip(int a, int b) { return (a ^= (1 << b)); }

std::string powtwo_string(int a) {
  if (((a & (a - 1)) == 0) && (a > 0)) {
    return "";
  } else {
    return "not ";
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << "<flag>" << std::endl
              << "'-s' for swap, '-p' for pow2, '-h' hamming, '-k' for kbit, "
                 "'-f' for flip"
              << std::endl;
    return 1;
  }

  char flag = argv[1][1];
  std::cout << "Flag: " << flag << std::endl;

  switch (flag) {
  case 's': {
    if (argc != 4) {
      std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <int1> <int2>"
                << std::endl;
      return 1;
    }
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    std::cout << "Before: " << a << " " << b << std::endl;
    swap_int(a, b);
    std::cout << "After: " << a << " " << b << std::endl;
    break;
  }

  case 'p': {
    if (argc != 3) {
      std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <int>"
                << std::endl;
      return 1;
    }
    int a = std::atoi(argv[2]);
    std::cout << "Input: " << a << std::endl;
    if (powtwo(a)) {
      std::cout << a << " is a power of 2" << std::endl;
    } else {
      std::cout << a << " is not a power of 2" << std::endl;
    }
    break;
  }

  case 'h': {
    if (argc != 3) {
      std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <int>"
                << std::endl;
      return 1;
    }
    int a = std::atoi(argv[2]);
    std::cout << "Talet " << a << " " << std::bitset<5>(a) << " har "
              << hamming(a) << " ettor." << std::endl;
    break;
  }
  case 'k': {
    if (argc != 4) {
      std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <int1> <int2>"
                << std::endl;
      return 1;
    }
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    std::cout << "Input: num = " << a << " (" << std::bitset<5>(a)
              << " in binary), k = " << b << std::endl;
    std::cout << "Output: " << kbit(a, b) << std::endl;
    break;
  }
  case 'f': {
    if (argc != 4) {
      std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <int1> <int2>"
                << std::endl;
      return 1;
    }
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    std::cout << "Input: num = " << a << " (" << std::bitset<5>(a)
              << " in binary), k = " << b << std::endl;
    std::cout << "Output: " << kflip(a, b) << " ("
              << std::bitset<5>(kflip(a, b)) << " in binary)" << std::endl;
    break;
  }
  case 'l': {
    if (argc != 3) {
      std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <int>"
                << std::endl;
      return 1;
    }
    int a = std::atoi(argv[2]);
    std::cout << "Input: " << a << std::endl;
    std::cout << a << " is " << powtwo_string(a) << "a power off 2."
              << std::endl;
    break;
  }

  default:
    std::cerr << "Error: Unknown flag " << argv[1] << std::endl;
    return 1;
  }
  return 0;
}
