#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixSub, Sub1) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double src_1[3][3] = {
      {0., 1., -1.}, {12., 13.45, 0.0123}, {-12., -13.45, -0.0123}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = 0;
    }
  S21Matrix m2 = m1;
  S21Matrix m1_old = m1;
  S21Matrix m2_old = m2;
  S21Matrix m_res = m1 - m2;
  EXPECT_EQ(m1.EqMatrix(m1_old), true);
  EXPECT_EQ(m2.EqMatrix(m2_old), true);
  EXPECT_EQ(m_res.EqMatrix(m_ref), true);
  m1.SubMatrix(m2);
  EXPECT_EQ(m1.EqMatrix(m_ref), true);
  m1_old -= m2;
  EXPECT_EQ(m1_old.EqMatrix(m_ref), true);
}

TEST(MatrixSub, Sub2) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);
  S21Matrix m_ref(3, 3);
  double src_1[3][3] = {
      {0., 1., -1.}, {12., 13.45, 0.0123}, {-12., -13.45, -0.0123}};
  double src_2[3][3] = {{0., 0., 0.}, {0., 0., 0.}, {0., 0., 0.}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m2(i, j) = src_2[i][j];
      m_ref(i, j) = src_1[i][j] + src_2[i][j];
    }
  S21Matrix m1_old = m1;
  S21Matrix m2_old = m2;
  S21Matrix m_res = m1 - m2;
  EXPECT_EQ(m1.EqMatrix(m1_old), true);
  EXPECT_EQ(m2.EqMatrix(m2_old), true);
  EXPECT_EQ(m_res.EqMatrix(m_ref), true);
  m1.SubMatrix(m2);
  EXPECT_EQ(m1.EqMatrix(m_ref), true);
  m1_old -= m2;
  EXPECT_EQ(m1_old.EqMatrix(m_ref), true);
}

TEST(MatrixSub, IncorrectDimensions) {
  bool flag = false;
  S21Matrix m1(4, 4);
  S21Matrix m2(3, 4);
  try {
    m1 -= m2;
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Different matrix dimensions.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}