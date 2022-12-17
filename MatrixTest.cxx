#define BOOST_TEST_MODULE test_matrix

#include "matrix.h"

#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_matrix)

BOOST_AUTO_TEST_CASE(simpleTest) {
  Matrix<int, -1> m;

  BOOST_CHECK(m.size() == 0);
  auto a = m[0][0];
  BOOST_CHECK(a == -1);
  BOOST_CHECK(m.size() == 0);
  m[100][100] = 314;
  BOOST_CHECK(m[100][100] == 314);
  BOOST_CHECK(m.size() == 1);

  for (auto c : m) {
    int row;
    int col;
    int value;
    std::tie(row, col, value) = c;
    std::cout << row << col << value << std::endl;
  }
}

BOOST_AUTO_TEST_CASE(chessTest) {
  const int value = -1;
  int size = 10;
  int value_iter = 0;

  Matrix <int, -1> m;
  for(int i = 0; i < size; ++i) {
    for(int j = i % 2; j < size; j += 2) {
      m[i][j] = value;
      ++value_iter;
    }
  }
  std::cout <<"value iterations: " << value_iter << std::endl;
  std::cout <<"size: " << m.size() << std::endl;

  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      std::cout << m[i][j]  << " " ;
    }
    std::cout << std::endl;
  }
}

BOOST_AUTO_TEST_SUITE_END()
