#ifndef UTILS_HPP
#define UTILS_HPP

#include "../s21_matrix_oop.h"

double **createMatrix(int rows, int cols);
double **resizeMatrix(int rows, int cols, double **old_matrix, int old_rows,
                      int old_cols);
bool isEqDouble(double a, double b);
double calcElementMulMatrix(double **m1, double **m2, int n, int i, int j);
double calcDeterminant(S21Matrix &src);

#endif  // UTILS_HPP