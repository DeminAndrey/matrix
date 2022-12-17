#include "matrix.h"

#include <cassert>
#include <iostream>
#include <iomanip>


void print1() {
  Matrix <int, 0> m;
  for (auto i = 0 ; i < 10 ; i++){
    m[i][i] = i;
    m[i][9 - i] = 9 - i;
  }
  for (auto i = 1 ; i < 9 ; i++) {
    for (auto j = 1 ; j < 9; j++) {
      std::cout << std::setw(3) << m[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "value = " << m.size()  <<  std::endl;
}

void print2() {
  Matrix <int, 0> m;
  for (auto i = 0 ; i < 10 ; i++){
    m[i][i] = i;
    m[i][9 - i] = 9 - i;
  }
  for (auto c : m) {
    int i;
    int j;
    int value;
    std::tie(i, j, value) = c;
    std::cout << "i = " <<  i <<
                 " j = "<<  j <<
                 " value = " << value << std::endl;
  }
}

void print3() {
  Matrix <int, -1> m;
  ((m[100][100] = 314) = 0) = 217;
  std::cout << m[100][100] << std::endl;
  std::cout << m[10000][100000] << std::endl;
}

int main() {
  print1();
  print2();
  print3();
}
