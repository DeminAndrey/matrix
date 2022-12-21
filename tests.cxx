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
}

BOOST_AUTO_TEST_CASE(canonTest) {
  Matrix <int, -1> m;
  ((m[100][100] = 314) = 0) = 217;

  BOOST_CHECK(m[100][100] == 217);
}

BOOST_AUTO_TEST_SUITE_END()
