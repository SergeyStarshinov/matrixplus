#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixComplements, CalcComplements1) {
  S21Matrix m1(1, 1);
  m1(0, 0) = 5.55;
  S21Matrix m_res = m1.CalcComplements();
  EXPECT_DOUBLE_EQ(m_res(0, 0), 1.);
}

TEST(MatrixComplements, CalcComplements2) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double src_1[3][3] = {{1., 2., 3.}, {0., 4., 2.}, {5., 2., 1.}};
  double src_2[3][3] = {{0., 10., -20.}, {4., -14., 8.}, {-8., -2., 4.}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_2[i][j];
    }
  S21Matrix m_res = m1.CalcComplements();
  EXPECT_EQ(m_res == m_ref, true);
}

TEST(MatrixComplements, CalcComplements3) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double src_1[3][3] = {{2., 5., 7.}, {6., 3., 4.}, {5., -2., -3.}};
  double src_2[3][3] = {{-1., 38., -27.}, {1., -41., 29.}, {-1., 34., -24.}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_2[i][j];
    }
  S21Matrix m_res = m1.CalcComplements();
  EXPECT_EQ(m_res == m_ref, true);
}

TEST(MatrixComplements, IncorrectDimensions) {
  bool flag = false;
  S21Matrix m1(3, 4);
  try {
    m1.CalcComplements();
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "The matrix is not square.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}