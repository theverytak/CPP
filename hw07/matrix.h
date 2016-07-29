// matrix.h
// 2016. 7. 29

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Matrix {
 public:
  Matrix();
  Matrix(const Matrix& m);
  Matrix(int rows, int cols);

  int rows() const { return rows_; }
  int cols() const { return cols_; }
  void Resize(int rows, int cols) {
    values_.resize((rows_ = rows) * (cols_ = cols));
  }

  // return the element of (r, c)
  // ex) Matrix m(3,4);
  int& operator()(int r, int c) { return values_[Sub2Ind(r,c)]; }
  const int& operator()(int r, int c) const { return values_[Sub2Ind(r,c)]; }

  Matrix operator+() const;  // Unary operators
  Matrix operator-() const;  // ex) Matrix m(2,3); cout << -m;

  // change element by using downward diagonal as a mirror;
  Matrix Transpose() const;

 private:
  // get row and col and return the index of element in the array;
  int Sub2Ind(int r, int c) const { return r + c * rows_; }

  vector<int> values_;
  int rows_, cols_;
};


istream& operator>>(istream& is, Matrix& m);
ostream& operator<<(ostream& os, const Matrix& m);

// 행렬연산. 왼쪽 행렬과 오른쪽 행렬의 크기가 맞지 않아 계산이 되지 않는 경우
// matrix calculation. if calc can't be done becuz of the size difference of left and right
// cout << "Invalid operation" << endl;
// and exit(0);

Matrix operator+(const Matrix& lm, const Matrix& rm);
Matrix operator-(const Matrix& lm, const Matrix& rm);

// matrix mult. the size of left col and right row should be same.
// if diff, look the remark above.
Matrix operator*(const Matrix& lm, const Matrix& rm);

Matrix operator+(const int& a, const Matrix& rm);
Matrix operator-(const int& a, const Matrix& rm);
Matrix operator*(const int& a, const Matrix& rm);
Matrix operator+(const Matrix& lm, const int& a);
Matrix operator-(const Matrix& lm, const int& a);
Matrix operator*(const Matrix& lm, const int& a);

bool ParseMatrix(const map<string, Matrix>& matrices, const string& str,
                 Matrix* mat);

#endif // _MATRIX_H_
