#pragma once

#include<vector>

class Matrix {
 public:
    Matrix(size_t h, size_t w);  // Initializes to 0 matrix
    Matrix(const Matrix& rhs);  // Copy constructor
    Matrix(Matrix&& rhs);  // Move constructor
    ~Matrix();

    // Accessors
    size_t width() const { return cols; }
    size_t height() const { return rows; }
    size_t size() const { return rows * cols; }

    Matrix& operator=(const Matrix& rhs);  // Copy assignment
    Matrix& operator=(Matrix&& rhs);  // Move assignment
    Matrix& operator+=(const Matrix& rhs);  // Increment

    // Element access
    double& operator()(size_t r, size_t c);
    const double& operator()(size_t r, size_t c) const;
    double& at(size_t r, size_t c);
    const double& at(size_t r, size_t c) const;
    double* operator[](size_t r);
    const double* operator[](size_t r) const;
 private:
    size_t rows;
    size_t cols;
    double* matrix;
};

// Math operators
Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
