#include "bitops.h"
#include <gtest/gtest.h>

TEST(SwapTest, TenTwenty) {
  int a = 10;
  int b = 20;

  swap_int(a, b);

  EXPECT_EQ(a, 20);
  EXPECT_EQ(b, 10);
}
TEST(SwapTest, FifteenForty) {
  int a = 15;
  int b = 40;

  swap_int(a, b);

  EXPECT_EQ(a, 40);
  EXPECT_EQ(b, 15);
}
