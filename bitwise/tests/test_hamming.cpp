#include "bitops.h"
#include <gtest/gtest.h>

TEST(HammingTest, ValidInput) {
  EXPECT_EQ(hamming(9), 2);
  EXPECT_EQ(hamming(15), 4);
  EXPECT_EQ(hamming(7), 3);
  EXPECT_EQ(hamming(8), 1);
}

TEST(HammingTest, NegativeValues) {
  EXPECT_EQ(hamming(-1), -1);
  EXPECT_EQ(hamming(-5), -1);
  EXPECT_EQ(hamming(-1005), -1);
}
