#include "bitops.h"
#include <gtest/gtest.h>

TEST(KFlipTest, Flippin) {
  EXPECT_EQ(kflip(13, 1), 15);
  EXPECT_EQ(kflip(13, 2), 9);
}
