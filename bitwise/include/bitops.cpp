#include "bitops.h"
#include <bitset>
#include <iostream>

void swap_int(int &a, int &b) {
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
}

int hamming(int a) {
  if (a < 0) {
    return -1;
  }
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

std::string powtwo(int a) {
  return (((a & (a - 1)) == 0) && (a > 0)) ? "" : "not ";
}
