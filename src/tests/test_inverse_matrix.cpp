#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(InverseMatrix, CalcComplements1) {
  S21Matrix m1(1, 1);
  m1(0, 0) = 5.;
  S21Matrix m_res = m1.InverseMatrix();
  EXPECT_DOUBLE_EQ(m_res(0, 0), 0.2);
}

TEST(InverseMatrix, CalcComplements2) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double src_1[3][3] = {{2., 5., 7.}, {6., 3., 4.}, {5., -2., -3.}};
  double src_2[3][3] = {{1., -1., 1.}, {-38., 41., -34.}, {27., -29., 24.}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_2[i][j];
    }
  S21Matrix m1_old = m1;
  S21Matrix m_res = m1.InverseMatrix();
  EXPECT_EQ(m_res == m_ref, true);
  EXPECT_EQ(m1_old == m1, true);
}

TEST(InverseMatrix, CalcComplements3) {
  S21Matrix m1(3, 3);
  S21Matrix m_ref(3, 3);
  double src_1[3][3] = {{-1., -1., 1.}, {0., 5., 1.}, {0., 0., -1.}};
  double src_2[3][3] = {{-1., -0.2, -1.2}, {-0., 0.2, 0.2}, {0., -0., -1.}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      m1(i, j) = src_1[i][j];
      m_ref(i, j) = src_2[i][j];
    }
  S21Matrix m1_old = m1;
  S21Matrix m_res = m1.InverseMatrix();
  EXPECT_EQ(m_res == m_ref, true);
  EXPECT_EQ(m1_old == m1, true);
}

TEST(InverseMatrix, IncorrectDimensions) {
  bool flag = false;
  S21Matrix m1(3, 4);
  try {
    m1.InverseMatrix();
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "The matrix is not square.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}

TEST(InverseMatrix, DeterminantIsZero) {
  bool flag = false;
  S21Matrix m1(3, 3);
  double src[3][3] = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) m1(i, j) = src[i][j];
  try {
    m1.InverseMatrix();
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Matrix determinant is 0.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}
