#pragma once

#include "Iterator.h"
#include "phys_matrix.h"

#include <map>
#include <utility>

template<typename T, T value>
class Matrix {
  PhysicaMatrix<T, value> m_data;

public: 
  Matrix() = default;

  auto size() const;
  auto& operator[](size_t row);
  auto begin();
  auto end();

private:
  Matrix(const Matrix&) = delete;
  Matrix& operator=(const Matrix&) = delete;
};

template<typename T, T value>
auto Matrix<T, value>::size() const {
  return m_data.size();
}

template<typename T, T value>
auto& Matrix<T, value>::operator[](size_t row) {
  m_data.setRow(row);
  return m_data;
}

template<typename T, T value>
auto Matrix<T, value>::begin()  {
  return matrix_iterator<T>(m_data.begin());
}

template<typename T, T value>
auto Matrix<T, value>::end() {
  return matrix_iterator<T>(m_data.end());
}
