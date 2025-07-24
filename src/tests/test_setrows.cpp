#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(SetRows, incRows) {
  S21Matrix m1(2, 2);
  S21Matrix m_ref(4, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      m1(i, j) = 10 * i + j;
      m_ref(i, j) = 10 * i + j;
    }
  }
  for (int i = 2; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      m_ref(i, j) = 0;
    }
  }
  m1.setRows(4);
  EXPECT_EQ(m1.getRows(), 4);
  EXPECT_EQ(m1.getCols(), 2);
  EXPECT_EQ(m1 == m_ref, true);
}

TEST(SetRows, decRows) {
  S21Matrix m1(4, 2);
  S21Matrix m_ref(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      m1(i, j) = 10 * i + j;
      m_ref(i, j) = 10 * i + j;
    }
  }
  for (int i = 2; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      m1(i, j) = 10 * i + j;
    }
  }
  m1.setRows(2);
  EXPECT_EQ(m1.getRows(), 2);
  EXPECT_EQ(m1.getCols(), 2);
  EXPECT_EQ(m1 == m_ref, true);
}

TEST(SetRows, IncorrectRows1) {
  S21Matrix m1(4, 2);
  bool flag = false;
  try {
    m1.setRows(0);
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Incorrect matrix dimension.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}

TEST(SetRows, IncorrectRows2) {
  S21Matrix m1(4, 2);
  bool flag = false;
  try {
    m1.setRows(-2);
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Incorrect matrix dimension.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}