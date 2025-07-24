#include "../s21_matrix_oop.h"
#include "utils.hpp"

/**
 * @brief Конструктор по умолчанию.
 *
 * Вызывается конструктор по параметрам с заранее заданной размерностью матрицы
 */
S21Matrix::S21Matrix() : S21Matrix(DEFAULT_ROWS, DEFAULT_COLS) {}

/**
 * @brief Конструктор по параметрам.
 */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range("Incorrect matrix dimension.");
  }
  matrix_ = createMatrix(rows_, cols_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = 0;
}

/**
 * @brief Конструктор копированием.
 */
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = createMatrix(rows_, cols_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
}

/**
 * @brief Конструктор перемещением.
 */
S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

/**
 * @brief Деструктор.
 */
S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) delete[] matrix_[0];
  delete[] matrix_;
  matrix_ = nullptr;
}

/**
 * @brief accessor к rows_.
 */
int S21Matrix::getRows() const { return rows_; }

/**
 * @brief accessor к cols_.
 */
int S21Matrix::getCols() const { return cols_; }

/**
 * @brief Индексация по элементам матрицы (строка, колонка).
 */
double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Index is out of range.");
  }
  return matrix_[row][col];
}

/**
 * @brief Индексация по элементам матрицы (строка, колонка) для const объектов.
 */
double S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Index is out of range.");
  }
  return matrix_[row][col];
}

/**
 * @brief Оператор присваивания.
 */
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (&other != this) {
    delete[] matrix_[0];
    delete[] matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = createMatrix(rows_, cols_);
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
  }
  return *this;
}

/**
 * @brief Проверка матриц на равенство.
 */
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool res = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    res = false;
  } else {
    for (int i = 0; i < rows_ && res; ++i) {
      for (int j = 0; j < cols_ && res; ++j) {
        res = isEqDouble(matrix_[i][j], other.matrix_[i][j]);
      }
    }
  }
  return res;
}

/**
 * @brief Проверка матриц на равенство через оператор ==.
 */
bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

/**
 * @brief Проверка матриц на неравенство через оператор !=.
 */
bool S21Matrix::operator!=(const S21Matrix &other) { return !EqMatrix(other); }

/**
 * @brief Mutator для rows_.
 */
void S21Matrix::setRows(int rows) {
  if (rows <= 0) {
    throw std::out_of_range("Incorrect matrix dimension.");
  }
  matrix_ = resizeMatrix(rows, cols_, matrix_, rows_, cols_);
  rows_ = rows;
}

/**
 * @brief Mutator для cols_.
 */
void S21Matrix::setCols(int cols) {
  if (cols <= 0) {
    throw std::out_of_range("Incorrect matrix dimension.");
  }
  matrix_ = resizeMatrix(rows_, cols, matrix_, rows_, cols_);
  cols_ = cols;
}