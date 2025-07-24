#include "../s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(MatrixInit, DefaultInit) {
  S21Matrix m1;
  EXPECT_EQ(m1.getRows(), DEFAULT_ROWS);
  EXPECT_EQ(m1.getCols(), DEFAULT_COLS);
  EXPECT_EQ(m1(0, 0), 0);
}

TEST(MatrixInit, ParamInit) {
  S21Matrix m1(4, 5);
  EXPECT_EQ(m1.getRows(), 4);
  EXPECT_EQ(m1.getCols(), 5);
  EXPECT_EQ(m1(3, 4), 0);
}

TEST(MatrixInit, IncorrectParamInit) {
  bool flag = false;
  try {
    S21Matrix m1(4, 0);
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Incorrect matrix dimension.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}

TEST(MatrixInit, CopyInit) {
  S21Matrix m1(4, 5);
  m1(3, 4) = 1.24;
  S21Matrix const m2 = m1;
  EXPECT_EQ(m1.getRows(), 4);
  EXPECT_EQ(m1.getCols(), 5);
  EXPECT_EQ(m1(3, 4), 1.24);
  EXPECT_EQ(m2.getRows(), 4);
  EXPECT_EQ(m2.getCols(), 5);
  EXPECT_EQ(m2(3, 4), 1.24);
}

TEST(MatrixInit, MoveInit) {
  S21Matrix m1(4, 5);
  m1(3, 4) = 1.24;
  S21Matrix m2 = std::move(m1);
  EXPECT_EQ(m2.getRows(), 4);
  EXPECT_EQ(m2.getCols(), 5);
  EXPECT_EQ(m2(3, 4), 1.24);
  EXPECT_EQ(m1.getRows(), 0);
  EXPECT_EQ(m1.getCols(), 0);
}

TEST(MatrixInit, IncorrectIndex1) {
  bool flag = false;
  try {
    S21Matrix m1(4, 5);
    m1(4, 5) = 1;
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Index is out of range.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}

TEST(MatrixInit, IncorrectIndex2) {
  bool flag = false;
  try {
    S21Matrix m1(4, 5);
    m1(-1, 0) = 1;
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Index is out of range.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}

TEST(MatrixInit, IncorrectIndex3) {
  bool flag = false;
  try {
    S21Matrix const m1(4, 5);
    double x = m1(-1, 0);
    if (x == 0) x = m1.getRows();
  } catch (const std::exception& err) {
    EXPECT_STREQ(err.what(), "Index is out of range.");
    flag = true;
  }
  EXPECT_EQ(flag, true);
}