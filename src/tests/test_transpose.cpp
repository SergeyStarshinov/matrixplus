#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixTranspose, Transpose1) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double src_1[3][3] = {
      {0., 1., -1.}, {12., 13.45, 0.0123}, {-12., -13.45, -0.0123}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_1[j][i];
    }
  S21Matrix m1_old = m1;
  S21Matrix m2 = m1.Transpose();
  EXPECT_EQ(m2 == m_ref, true);
  EXPECT_EQ(m1 == m1_old, true);
}

TEST(MatrixTranspose, Transpose2) {
  S21Matrix m1(2, 3);
  S21Matrix m_ref(3, 2);
  double src_1[2][3] = {{0., 1., -1.},
                        {12345678912345.67, 123.4567899, 0.012345678}};
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(j, i) = src_1[i][j];
    }
  S21Matrix m1_old = m1;
  S21Matrix m2 = m1.Transpose();
  EXPECT_EQ(m2 == m_ref, true);
  EXPECT_EQ(m1 == m1_old, true);
}
