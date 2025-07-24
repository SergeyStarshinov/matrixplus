#include "utils.hpp"

/**
 * @brief Создание двумерного массива заданной размерности.
 */
double **createMatrix(int rows, int cols) {
  double **matrix = new double *[rows];
  matrix[0] = new double[rows * cols];
  for (int i = 1; i < rows; ++i) matrix[i] = matrix[i - 1] + cols;
  return matrix;
}

double **resizeMatrix(int rows, int cols, double **old_matrix, int old_rows,
                      int old_cols) {
  double **new_matrix = new double *[rows];
  new_matrix[0] = new double[rows * cols];
  for (int i = 1; i < rows; ++i) new_matrix[i] = new_matrix[i - 1] + cols;
  int min_rows = rows > old_rows ? old_rows : rows;
  int min_cols = cols > old_cols ? old_cols : cols;
  for (int i = 0; i < min_rows; ++i) {
    for (int j = 0; j < min_cols; ++j) new_matrix[i][j] = old_matrix[i][j];
    for (int j = min_cols; j < cols; ++j) new_matrix[i][j] = 0;
  }
  for (int i = min_rows; i < rows; ++i)
    for (int j = 0; j < cols; ++j) new_matrix[i][j] = 0;

  delete[] old_matrix[0];
  delete[] old_matrix;
  return new_matrix;
}

/**
 * @brief Проверка равенства двух числе типа double с заданной точностью.
 */
bool isEqDouble(double a, double b) {
  bool res = abs(a - b) < 1e-8;
  return res;
}

/**
 * @brief Вычисляет элемент с координатами (i , j) при умножении матриц m1 и m2.
 */
double calcElementMulMatrix(double **m1, double **m2, int n, int i, int j) {
  double sum = 0;
  for (int k = 0; k < n; k++) {
    sum += m1[i][k] * m2[k][j];
  }
  return sum;
}

/**
 * @brief Вычисляет детерминант матрицы через рекурсию.
 */
double calcDeterminant(S21Matrix &src) {
  double res = 0.;
  if (src.getRows() == 1) {
    res = src(0, 0);
  } else {
    int k = 1;
    for (int i = 0; i < src.getRows(); ++i) {
      S21Matrix tmp = src.createMinor(i, 0);
      res += src(i, 0) * k * calcDeterminant(tmp);
      k *= -1;
    }
  }
  return res;
}