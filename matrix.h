#pragma once

#include "Iterator.h"
#include "phys_matrix.h"

#include <map>
#include <utility>

/**
 * класс-обертка над 2-мерной разреженной бесконечной матрицы
 */
template<typename T, T value>
class Matrix {
  PhysicaMatrix<T, value> m_data;

public: 
  Matrix() = default;
  ~Matrix() = default;

  /**
   * @brief size возращает количество занятых ячеек
   */
  size_t size() const;
  auto& operator[](size_t row);

  /**
   * @brief begin возвращает указатель на первую занятую ячейку
   */
  auto begin();

  /**
   * @brief end возвращает указатель конца занятых ячеек
   */
  auto end();

private:
  Matrix(const Matrix&) = delete;
  Matrix& operator=(const Matrix&) = delete;
};

template<typename T, T value>
size_t Matrix<T, value>::size() const {
  return m_data.size();
}

template<typename T, T value>
auto& Matrix<T, value>::operator[](size_t row) {
  m_data.setRow(row);
  return m_data;
}

template<typename T, T value>
auto Matrix<T, value>::begin()  {
  return MatrixIterator<T>(m_data.begin());
}

template<typename T, T value>
auto Matrix<T, value>::end() {
  return MatrixIterator<T>(m_data.end());
}
