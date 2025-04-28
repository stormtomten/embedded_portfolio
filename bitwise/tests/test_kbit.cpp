#include "bitops.h"
#include <gtest/gtest.h>

TEST(KBitTest, KBitPositives) {
  EXPECT_EQ(kbit(13, 1), 0);
  EXPECT_EQ(kbit(13, 2), 1);
  EXPECT_EQ(kbit(13, 3), 1);
}
