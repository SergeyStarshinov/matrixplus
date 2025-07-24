#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixEq, fail1) {
  S21Matrix m1(3, 2);
  S21Matrix m2(2, 2);
  S21Matrix m3(2, 3);
  EXPECT_EQ(m1.EqMatrix(m2), false);
  EXPECT_EQ(m1.EqMatrix(m3), false);
  EXPECT_EQ(m2.EqMatrix(m1), false);
  EXPECT_EQ(m2.EqMatrix(m3), false);
  EXPECT_EQ(m3.EqMatrix(m1), false);
  EXPECT_EQ(m3.EqMatrix(m2), false);
  EXPECT_EQ(m1 != m2, true);
  EXPECT_EQ(m2 != m3, true);
  EXPECT_EQ(m3 != m1, true);
}

TEST(MatrixEq, fail2) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  m2(2, 2) = 2.2;
  EXPECT_EQ(m1.EqMatrix(m2), false);
  EXPECT_EQ(m2.EqMatrix(m1), false);
  EXPECT_EQ(m1 == m2, false);
  EXPECT_EQ(m1 != m2, true);
  EXPECT_EQ(m2 != m1, true);
}

TEST(MatrixEq, success1) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  EXPECT_EQ(m1.EqMatrix(m2), true);
  EXPECT_EQ(m2.EqMatrix(m1), true);
  EXPECT_EQ(m1 == m2, true);
  EXPECT_EQ(m2 == m1, true);
}
