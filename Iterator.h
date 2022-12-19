#pragma once 

#include <map>
#include <tuple>

/**
 * класс итератора над данными для бесконечной матрицы
 */
template <typename T>
class MatrixIterator {
  using output_matrix_iterator =
  typename std::map<std::pair<std::size_t, std::size_t>, T>::iterator;

public:
  MatrixIterator(output_matrix_iterator iterator);
  ~MatrixIterator() = default;

  bool operator!=(MatrixIterator<T> const& other) const;
  bool operator==(MatrixIterator<T> const& other) const;

  auto operator*() const;
  auto operator++();

private:
  output_matrix_iterator iterator;
};


template<typename T>
MatrixIterator<T>::MatrixIterator(output_matrix_iterator iterator)
  : iterator(iterator) {}

template<typename T>
bool MatrixIterator<T>::operator!= (MatrixIterator<T> const& other) const {
  return iterator != other.iterator;
}

template<typename T>
bool MatrixIterator<T>::operator==(MatrixIterator<T> const& other) const {
  return iterator == other.iterator;
}

template<typename T>
auto MatrixIterator<T>::operator*() const {
  return std::make_tuple(iterator->first.first,
                         iterator->first.second,
                         iterator->second);
}

template<typename T>
auto MatrixIterator<T>::operator++() {
  iterator++;
  return *this;
}
