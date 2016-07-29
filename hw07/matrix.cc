// matrix.cc
// 2016. 7. 29

#include "matrix.h"

bool ParseMatrix(const map<string, Matrix>& matrices, const string& str,
                 Matrix* mat) {
  bool negate = false, transpose = false;
  string name = str;
  //   str="-a" => negate=true, transpose=false, name="a"
  //   str="b'" => negate=false, transpose=true, name="b"
  //   str="-c'" => negate=true, transpose=true, name="c"
  //   str="d" => negate=false, transpose=false, name="d"
  if(name.find("-") != string::npos) {
    negate = true;
    name.erase(name.begin());
  }
  if(name.find("\'") != string::npos) {
    transpose = true;
    name.erase(name.end() - 1);
  }

  map<string, Matrix>::const_iterator it = matrices.find(name);
  if (it == matrices.end()) return false;
  *mat = negate ? -it->second : it->second;
  if (transpose) *mat = mat->Transpose();
  return true;
}

// constructor
Matrix::Matrix() {}
Matrix::Matrix(const Matrix& m) {
  rows_ = m.rows_;
  cols_ = m.cols_;
  values_ = m.values_;
}
Matrix::Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  values_.resize(rows_ * cols_);
}

Matrix Matrix::operator+() const {
  return *this;
}

Matrix Matrix::operator-() const {
  Matrix mat = *this;
  for(int i = 0; i < mat.values_.size(); i++)
    mat.values_[i] *= -1;

  return mat;
}

Matrix Matrix::Transpose() const {
  Matrix mat(cols(), rows());   // a matrix for return.
  for(int i = 0; i < rows_; i++)
    for(int j = 0; j < cols_; j++)
      mat(j, i) = values_[Sub2Ind(i, j)];

  return mat;
}



istream& operator>>(istream& is, Matrix& m) {
  int rows, cols;
  is >> rows >> cols;
  m.Resize(rows, cols);

  for(int i = 0; i < m.rows(); i++)
    for(int j = 0; j < m.cols(); j++)
      is >> m(i, j);

  return is;
}

ostream& operator<<(ostream& os, const Matrix& m) {
  for(int i = 0; i < m.rows(); i++) {
    for(int j = 0; j < m.cols(); j++)
      os << m(i, j) << " ";
    os << endl;
  }

  return os;
}



Matrix operator+(const Matrix& lm, const Matrix& rm) {
  if(lm.rows() != rm.rows() || lm.cols() != rm.cols()) {
    cout << "Invalid operation" << endl;
    exit(0);
  }
  Matrix res(lm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) += rm(i, j);

  return res;
}

Matrix operator-(const Matrix& lm, const Matrix& rm) {
  if(lm.rows() != rm.rows() || lm.cols() != rm.cols()) {
    cout << "Invalid operation" << endl;
    exit(0);
  }
  Matrix res(lm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) -= rm(i, j);

  return res;
}

Matrix operator*(const Matrix& lm, const Matrix& rm) {
  if(lm.cols() != rm.rows()) {
    cout << "Invalid operation" << endl;
    exit(0);
  }

  Matrix res(lm.rows(), rm.cols());

  int sum = 0;

  for(int i = 0; i < lm.rows(); i++) {
    for(int j = 0; j < rm.cols(); j++) {
      for(int k = 0; k < rm.rows(); k++) {
        sum += lm(i, k) * rm(k, j);
      }
      res(i, j) = sum;
      sum = 0;
    }
  }

  return res;
}

Matrix operator+(const int& a, const Matrix& rm) {
  Matrix res(rm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) += a;

  return res;
}

Matrix operator-(const int& a, const Matrix& rm) {
  Matrix res(rm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) -= a;

  return res;
}

Matrix operator*(const int& a, const Matrix& rm) {
  Matrix res(rm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) *= a;

  return res;
}

Matrix operator+(const Matrix& lm, const int& a) {
  Matrix res(lm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) += a;

  return res;
}

Matrix operator-(const Matrix& lm, const int& a) {
  Matrix res(lm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) -= a;

  return res;
}
Matrix operator*(const Matrix& lm, const int& a) {
  Matrix res(lm);

  for(int i = 0; i < res.rows(); i++)
    for(int j = 0; j < res.cols(); j++)
      res(i, j) *= a;

  return res;
}
