#include "bitops.h"
#include <gtest/gtest.h>

// Testa powtwo_string-funktionen
TEST(PowtwoTest, PositivePowerOfTwo) {
  EXPECT_EQ(powtwo(2), ""); // 2 är en makt av 2
  EXPECT_EQ(powtwo(4), ""); // 4 är en makt av 2
  EXPECT_EQ(powtwo(8), ""); // 8 är en makt av 2
}

TEST(PowtwoTest, NegativeAndNonPowerOfTwo) {
  EXPECT_EQ(powtwo(3), "not "); // 3 är inte en makt av 2
  EXPECT_EQ(powtwo(5), "not "); // 5 är inte en makt av 2
  EXPECT_EQ(powtwo(7), "not "); // 7 är inte en makt av 2
}

TEST(PowtwoTest, ZeroAndNegativeNumbers) {
  EXPECT_EQ(powtwo(0), "not ");  // 0 är inte en makt av 2
  EXPECT_EQ(powtwo(-4), "not "); // Negativa tal är inte makter av 2
}
