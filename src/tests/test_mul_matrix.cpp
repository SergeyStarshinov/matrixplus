#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MulMatrix, MulMatrix1) {
  int m = 3;
  int n = 2;
  S21Matrix m1(m, n);
  S21Matrix m2(n, m);
  S21Matrix m_ref(m, m);

  double src_1[3][2] = {{1., 4.}, {2., 5.}, {3., 6.}};
  double src_2[2][3] = {{1., -1., 1.}, {2., 3., 4.}};
  double src_3[3][3] = {{9., 11., 17.}, {12., 13., 22.}, {15., 15., 27.}};

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      m1(i, j) = src_1[i][j];
      m2(j, i) = src_2[j][i];
    }
    for (int j = 0; j < m; ++j) m_ref(i, j) = src_3[i][j];
  }
  S21Matrix m3 = m1 * m2;
  EXPECT_EQ(m3 == m_ref, true);
  S21Matrix m1_old = m1;
  m1.MulMatrix(m2);
  EXPECT_EQ(m1 == m_ref, true);
  m1_old *= m2;
  EXPECT_EQ(m1_old == m_ref, true);
}

TEST(MulMatrix, MulMatrix2) {
  int m = 2;
  int n = 3;
  S21Matrix m1(m, n);
  S21Matrix m2(n, m);
  S21Matrix m_ref(m, m);

  double src_1[2][3] = {{-1., 15., 0.}, {0., 1., -0.25}};
  double src_2[3][2] = {{1., -1.}, {0.5, -0.5}, {12., -12.}};
  double src_3[2][2] = {{6.5, -6.5}, {-2.5, 2.5}};

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      m1(i, j) = src_1[i][j];
      m2(j, i) = src_2[j][i];
    }
    for (int j = 0; j < m; ++j) m_ref(i, j) = src_3[i][j];
  }
  S21Matrix m3 = m1 * m2;
  EXPECT_EQ(m3 == m_ref, true);
  S21Matrix m1_old = m1;
  m1.MulMatrix(m2);
  EXPECT_EQ(m1 == m_ref, true);
  m1_old *= m2;
  EXPECT_EQ(m1_old == m_ref, true);
}

TEST(MulMatrix, IncorrectDimensions) {
  bool flag = false;
  S21Matrix m1(4, 4);
  S21Matrix m2(3, 4);
  try {
    m1.MulMatrix(m2);
  } catch (const std::exception& err) {
    EXPECT_STRNE(err.what(), "");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}