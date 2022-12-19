#pragma once

#include <iostream>
#include <map>
#include <utility>

/**
 * класс 2-мерной разреженной бесконечной матрицы
 */
template<typename T, T value>
class PhysicaMatrix {
  using matrix_position = std::pair<size_t, size_t>;

  static const T defaultValue = value;
  std::map<matrix_position, T> m_matrix;
  matrix_position m_current;

public:
  PhysicaMatrix() = default;
  ~PhysicaMatrix() = default;

  /**
   * @brief size возращает количество занятых ячеек
   */
  size_t size() const;

  /**
   * @brief setRow устанавливает как текущий ряд матрицы
   *  по которому идет обращение к матрице
   * @param row значение ряда (первый индекс)
   */
  void setRow(size_t row);

  PhysicaMatrix& operator[](size_t pos);
  PhysicaMatrix& operator=(const T& other);
  bool operator==(T val) const;

  /**
   * @brief begin возвращает указатель на первую занятую ячейку
   */
  auto begin();

  /**
   * @brief end возвращает указатель конца занятых ячеек
   */
  auto end();

  template<typename Type, Type val>
  friend std::ostream& operator<<(
      std::ostream& out, const PhysicaMatrix<Type, val>& m);
};

/**
 * перегруженный оператор вывода в поток матрицы
 */
template<typename Type, Type val>
std::ostream& operator<<(std::ostream& out,
                         const PhysicaMatrix<Type, val>& m) {
  auto it = m.m_matrix.find(m.m_current);
  auto output = (it != m.m_matrix.end())
      ? it->second : val;
  out << output;

  return out;
}

template<typename T, T value>
size_t PhysicaMatrix<T, value>::size() const {
  return m_matrix.size();
}

template<typename T, T value>
void PhysicaMatrix<T, value>::setRow(size_t row) {
  m_current.first = row;
}

template<typename T, T value>
PhysicaMatrix<T, value>& PhysicaMatrix<T, value>::operator[](size_t pos) {
  m_current.second = pos;
  return *this;
}

template<typename T, T value>
PhysicaMatrix<T, value>& PhysicaMatrix<T, value>::operator=(const T& other) {
  if (other != defaultValue) {
    m_matrix[m_current] = other;
  }
  else {
    auto it = m_matrix.find(m_current);
    if ( it != m_matrix.end())
      m_matrix.erase(it->first);
  }
  return *this;
}

template<typename T, T value>
bool PhysicaMatrix<T, value>::operator==(T val) const {
  auto it = m_matrix.find(m_current);
  if (it != m_matrix.end()) {
    return (it->second == val) ? true : false;
  }
  else {
    return (val == defaultValue) ? true : false;
  }
}

template<typename T, T value>
auto PhysicaMatrix<T, value>::begin() {
  return m_matrix.begin();
};

template<typename T, T value>
auto PhysicaMatrix<T, value>::end() {
  return m_matrix.end();
}
