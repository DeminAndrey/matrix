#pragma once

#include <map>
#include <utility>

template<typename T, T value>
class PhysicaMatrix {
  using matrix_position = std::pair<size_t, size_t>;

  static constexpr T _default = value;
  std::map<matrix_position, T> matrix;
  matrix_position pair;

public:
  PhysicaMatrix() = default;

  size_t size() const;
  void setRow(size_t row);

  PhysicaMatrix& operator[](size_t pos);
  auto& operator=(const T& other);
  operator auto();

  auto begin();
  auto end();
};

template<typename T, T value>
size_t PhysicaMatrix<T, value>::size() const {
  return matrix.size();
}

template<typename T, T value>
PhysicaMatrix<T, value>& PhysicaMatrix<T, value>::operator[](size_t pos) {
  pair.second = pos;
  return *this;
}

template<typename T, T value>
auto& PhysicaMatrix<T, value>::operator=(const T& other) {
  if (other != _default) {
    matrix[pair] = other;
  }
  else {
    auto it = matrix.find(pair);
    if ( it != matrix.end())
      matrix.erase(it->first);
  }
  return *this;
}

template<typename T, T value>
void PhysicaMatrix<T, value>::setRow(size_t row) {
  pair.first = row;
}

template<typename T, T value>
auto PhysicaMatrix<T, value>::begin() {
  return matrix.begin();
};

template<typename T, T value>
auto PhysicaMatrix<T, value>::end() {
  return matrix.end();
}

template<typename T, T value>
PhysicaMatrix<T, value>::operator auto() {
  auto it = matrix.find(pair);
  return (it != matrix.end()) ? it->second : value;
}
