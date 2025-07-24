#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixSum, Assignment) {
  S21Matrix m1(3, 3);
  S21Matrix m2(2, 3);
  double src_1[3][3] = {
      {0., 1., -1.}, {12., 13.45, 0.0123}, {-12., -13.45, -0.0123}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
    }
  m1 = m1;
  EXPECT_EQ(m1.EqMatrix(m2), false);
  m2 = m1;
  EXPECT_EQ(m1.EqMatrix(m2), true);
  m2 += m1;
  EXPECT_EQ(m1.EqMatrix(m2), false);
  m2 = m1;
  EXPECT_EQ(m1.EqMatrix(m2), true);
}