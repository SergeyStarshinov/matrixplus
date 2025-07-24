#ifndef S21MATRIX_OOP_H
#define S21MATRIX_OOP_H

#include <cmath>
#include <stdexcept>

#define DEFAULT_ROWS 2
#define DEFAULT_COLS 3

class S21Matrix {
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

 public:
  S21Matrix();                        // default constructor
  S21Matrix(int rows, int cols);      // parameterized constructor
  S21Matrix(const S21Matrix& other);  // copy cnstructor
  S21Matrix(S21Matrix&& other);       // move cnstructor
  ~S21Matrix();                       // destructor
  int getRows() const;                // accessor to rows_
  int getCols() const;                // accessor to cols_
  void setRows(int rows);             // mutator for rows_
  void setCols(int cols);             // mutator for cols_

  // some operators overloads
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  friend S21Matrix operator*(double, S21Matrix&);
  bool operator==(const S21Matrix& other);
  bool operator!=(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int row, int col);
  double operator()(int row, int col) const;

  // some public methods
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix createMinor(int i, int j);
};

#endif  // S21MATRIX_OOP_H