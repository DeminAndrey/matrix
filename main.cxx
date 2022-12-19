#include "matrix.h"

#include <cassert>
#include <iomanip>
#include <iostream>

/**
 * печатает фрагмент матрицы от [1,1] до [8,8]
 */
template<typename T, T value>
void print_fragment(Matrix<T, value>& matrix) {
  for (auto i = 1; i < 9; i++) {
    for (auto j = 1 ; j < 9; j++) {
      std::cout << std::setw(3) << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * печатает количество занятых ячеек
 */
template<typename T, T value>
void print_size(Matrix<T, value>& matrix) {
  std::cout << "size = " << matrix.size()  <<  std::endl;
}

/**
 * печатает все занятые ячейки вместе со своими позициями
 */
template<typename T, T value>
void print_occupied(Matrix<T, value>& matrix) {
  for (auto c : matrix) {
    int i;
    int j;
    int value;
    std::tie(i, j, value) = c;
    std::cout << "i = " <<  i <<
                 " j = "<<  j <<
                 " value = " << value << std::endl;
  }
}


int main() {
  Matrix <int, 0> m;
  for (std::size_t i = 0; i < 10; i++) {
    m[i][i] = i;
    m[i][9 - i] = 9 - i;
  }

  print_fragment(m);
  print_size(m);
  print_occupied(m);

  return 0;
}
