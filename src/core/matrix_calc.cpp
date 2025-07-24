#include "../s21_matrix_oop.h"
#include "utils.hpp"

/**
 * @brief Создает новую транспонированную матрицу из текущей и возвращает ее.
 */
S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) res.matrix_[j][i] = matrix_[i][j];
  return res;
}

/**
 * @brief Вычисляет и возвращает определитель текущей матрицы.
 */
double S21Matrix::Determinant() {
  double det = 0;
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square.");
  } else {
    det = calcDeterminant(*this);
  }
  return det;
}

/**
 * @brief Создает минор для элемента с координатами (i, j).
 */
S21Matrix S21Matrix::createMinor(int excl_i, int excl_j) {
  S21Matrix res = S21Matrix(rows_ - 1, cols_ - 1);
  int minor_row = 0;
  int minor_col = 0;
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i != excl_i && j != excl_j) {
        res.matrix_[minor_row][minor_col++] = matrix_[i][j];
      }
    }
    if (i != excl_i) ++minor_row;
    minor_col = 0;
  }
  return res;
}

/**
 * @brief Вычисляет матрицу алгебраических дополнений текущей матрицы и
 * возвращает ее.
 */
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square.");
  }
  S21Matrix res(rows_, cols_);
  if (rows_ == 1) {
    res(0, 0) = 1.;
  } else {
    int k = 1;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        k = pow(-1, i + j);
        res(i, j) = k * this->createMinor(i, j).Determinant();
      }
    }
  }
  return res;
}

/**
 * @brief Вычисляет и возвращает обратную матрицу.
 */
S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix res(rows_, cols_);
  double det = this->Determinant();
  if (det == 0) {
    throw std::range_error("Matrix determinant is 0.");
  }
  res = this->CalcComplements().Transpose();
  res.MulNumber(1 / det);
  return res;
}
