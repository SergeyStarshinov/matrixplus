#include "../s21_matrix_oop.h"
#include "utils.hpp"

/**
 * @brief Прибавляет вторую матрицу к текущей.
 */
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
  } else {
    throw std::invalid_argument("Different matrix dimensions.");
  }
}

/**
 * @brief Перегрузка оператора +=.
 */
S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return *this;
}

/**
 * @brief Перегрузка оператора +.
 */
S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix res = *this;
  res.SumMatrix(other);
  return res;
}

/**
 * @brief Вычитает из текущей матрицы другую.
 */
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
  } else {
    throw std::invalid_argument("Different matrix dimensions.");
  }
}

/**
 * @brief Перегрузка оператора -=.
 */
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return *this;
}

/**
 * @brief Перегрузка оператора -.
 */
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix res = *this;
  res.SubMatrix(other);
  return res;
}

/**
 * @brief Умножение текущей матрицы на число.
 */
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] *= num;
}

/**
 * @brief Перегрузка оператора *= для умножения на число.
 */
S21Matrix &S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

/**
 * @brief Перегрузка оператора * для умножения матрицы на число.
 */
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res = *this;
  res.MulNumber(num);
  return res;
}

/**
 * @brief Перегрузка оператора * для умножения числа на матрицу.
 */
S21Matrix operator*(double num, S21Matrix &matrix) {
  S21Matrix res = matrix;
  res.MulNumber(num);
  return res;
}

/**
 * @brief Умножение текущей матрицы на другую матрицу.
 */
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ == other.rows_) {
    S21Matrix tmp(rows_, other.cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < other.cols_; ++j) {
        tmp.matrix_[i][j] =
            calcElementMulMatrix(this->matrix_, other.matrix_, cols_, i, j);
      }
    }
    *this = tmp;
  } else {
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix.");
  }
}

/**
 * @brief Перегрузка оператора *= для умножения матриц.
 */
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return *this;
}

/**
 * @brief Перегрузка оператора * для умножения матриц.
 */
S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix res = *this;
  res.MulMatrix(other);
  return res;
}
