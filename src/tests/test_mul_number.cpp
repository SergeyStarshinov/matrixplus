#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixMulNum, MulNumber1) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double num = 2.34;
  double src_1[3][3] = {
      {0., 1., -1.}, {12., 13.45, 0.0123}, {-12., -13.45, -0.0123}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_1[i][j] * num;
    }
  S21Matrix m2 = m1;
  m1.MulNumber(num);
  EXPECT_EQ(m1 == m_ref, true);
  m2 *= num;
  EXPECT_EQ(m2 == m_ref, true);
}

TEST(MatrixMulNum, MulNumber2) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double num = 0.;
  double src_1[3][3] = {
      {0., 0., 0.}, {12., 13.45, 0.0123}, {-12., -13.45, -0.0123}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_1[i][j] * num;
    }
  S21Matrix m2 = m1;
  m1.MulNumber(num);
  EXPECT_EQ(m1 == m_ref, true);
  m2 *= num;
  EXPECT_EQ(m2 == m_ref, true);
}

TEST(MatrixMulNum, MulNumber3) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double num = -5000000.;
  double src_1[3][3] = {{1.1234, 2.2345, -3.4567},
                        {12.12, -13.13, 0.0123},
                        {0., 10000.045, -0.0123}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_1[i][j] * num;
    }
  S21Matrix m2 = m1 * num;
  EXPECT_EQ(m2 == m_ref, true);
  m2 = num * m1;
  EXPECT_EQ(m2 == m_ref, true);
}