#include <gtest/gtest.h>
#include "../modulo_arithmetic.cpp"

class ModuloArithmeticTest : public ::testing::Test {
protected:
    const int MOD = 1e9 + 7;
    const int SMALL_MOD = 13;  // A smaller prime for testing
};

TEST_F(ModuloArithmeticTest, ModPlus) {
    EXPECT_EQ(modPlus(5, 3), 8);
    EXPECT_EQ(modPlus(MOD - 1, 2), 1);
    EXPECT_EQ(modPlus(MOD - 2, MOD - 3, SMALL_MOD), 7);
}

TEST_F(ModuloArithmeticTest, ModMinus) {
    EXPECT_EQ(modMinus(5, 3), 2);
    EXPECT_EQ(modMinus(2, 5), MOD - 3);
    EXPECT_EQ(modMinus(3, 8, SMALL_MOD), 8);
}

TEST_F(ModuloArithmeticTest, ModMult) {
    EXPECT_EQ(modMult(5, 3), 15);
    EXPECT_EQ(modMult(MOD - 1, 2), MOD - 2);
    EXPECT_EQ(modMult(6, 7, SMALL_MOD), 3);
}

TEST_F(ModuloArithmeticTest, ModPow) {
    EXPECT_EQ(modPow(2, 3), 8);
    EXPECT_EQ(modPow(2, 10), 1024);
    EXPECT_EQ(modPow(3, 4, SMALL_MOD), 3);
}

TEST_F(ModuloArithmeticTest, ModInv) {
    EXPECT_EQ(modMult(5, modInv(5)), 1);
    EXPECT_EQ(modMult(7, modInv(7)), 1);
    EXPECT_EQ(modMult(3, modInv(3, SMALL_MOD), SMALL_MOD), 1);
}

TEST_F(ModuloArithmeticTest, ModDiv) {
    EXPECT_EQ(modDiv(6, 2), 3);
    EXPECT_EQ(modDiv(15, 3), 5);
    EXPECT_EQ(modDiv(8, 4, SMALL_MOD), 2);
}

TEST_F(ModuloArithmeticTest, CombPrecompute) {
    Comb comb(10);
    EXPECT_EQ(comb.fac[0], 1);
    EXPECT_EQ(comb.fac[1], 1);
    EXPECT_EQ(comb.fac[2], 2);
    EXPECT_EQ(comb.fac[3], 6);
    EXPECT_EQ(comb.fac[4], 24);
}

TEST_F(ModuloArithmeticTest, SmallComb) {
    Comb comb(10);
    EXPECT_EQ(comb.small_comb(5, 2), 10);
    EXPECT_EQ(comb.small_comb(5, 0), 1);
    EXPECT_EQ(comb.small_comb(5, 5), 1);
    EXPECT_EQ(comb.small_comb(5, 6), 0);
}

TEST_F(ModuloArithmeticTest, Lucas) {
    Comb comb(10);
    EXPECT_EQ(comb.lucas(5, 2, SMALL_MOD), 9);
    EXPECT_EQ(comb.lucas(10, 3, SMALL_MOD), 8);
    EXPECT_EQ(comb.lucas(7, 0, SMALL_MOD), 1);
}
