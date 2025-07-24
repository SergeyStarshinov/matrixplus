#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixDet, Determinant1) {
  S21Matrix m1(1, 1);
  double ref = -2.345;
  m1(0, 0) = ref;
  EXPECT_DOUBLE_EQ(m1.Determinant(), ref);
}

TEST(MatrixDet, Determinant2) {
  S21Matrix m1(3, 3);
  double src[3][3] = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) m1(i, j) = src[i][j];

  EXPECT_DOUBLE_EQ(m1.Determinant(), 0.);
}

TEST(MatrixDet, Determinant3) {
  S21Matrix m1(2, 2);
  double src[2][2] = {{1., 2.}, {4., 5.}};
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) m1(i, j) = src[i][j];

  EXPECT_DOUBLE_EQ(m1.Determinant(), -3.);
}

TEST(MatrixDet, IncorrectDimensions) {
  bool flag = false;
  S21Matrix m1(3, 4);
  try {
    m1.Determinant();
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "The matrix is not square.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}