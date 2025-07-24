#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(SetCols, incCols) {
  S21Matrix m1(2, 2);
  S21Matrix m_ref(2, 4);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      m1(i, j) = 10 * i + j;
      m_ref(i, j) = 10 * i + j;
    }
    for (int j = 2; j < 4; ++j) {
      m_ref(i, j) = 0;
    }
  }

  m1.setCols(4);
  EXPECT_EQ(m1.getRows(), 2);
  EXPECT_EQ(m1.getCols(), 4);
  EXPECT_EQ(m1 == m_ref, true);
}

TEST(SetCols, decCols) {
  S21Matrix m1(2, 4);
  S21Matrix m_ref(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      m1(i, j) = 10 * i + j;
      m_ref(i, j) = 10 * i + j;
    }
    for (int j = 0; j < 4; ++j) {
      m1(i, j) = 10 * i + j;
    }
  }
  m1.setCols(2);
  EXPECT_EQ(m1.getRows(), 2);
  EXPECT_EQ(m1.getCols(), 2);
  EXPECT_EQ(m1 == m_ref, true);
}

TEST(SetCols, IncorrectCols1) {
  S21Matrix m1(3, 3);
  bool flag = false;
  try {
    m1.setCols(0);
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Incorrect matrix dimension.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}

TEST(SetColss, IncorrectCols2) {
  S21Matrix m1(3, 3);
  bool flag = false;
  try {
    m1.setCols(-2);
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Incorrect matrix dimension.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}