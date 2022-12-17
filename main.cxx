#include "matrix.h"

#include <cassert>
#include <iostream>
#include <iomanip>


void test_from_otus() {
    Matrix<int, -1> m;         // бесконечная матрица int заполнена значениями -1
    assert(m.size() == 0);     // все ячейки свободны
    auto a = m[0][0];
    //assert(a == -1);
    assert(m.size() == 0);
    m[100][100] = 314;
    //assert(m[100][100] == 314);
    assert(m.size() == 1);
    std::cout << __func__ << ": OK" << std::endl;
}
void test1() {
    Matrix <int, 0> m;
    for (auto i = 0 ; i < 10 ; i++){
    m[i][i] = i;
    m[i][9-i] = 9-i;
	}
    for (auto i = 1 ; i < 9 ; i++) {
		for (auto j = 1 ; j < 9; j++) {
      std::cout << std::setw(3) << m[i][j] << " ";
		}
		std::cout << std::endl;
	}	
   std::cout << "value = " << m.size()  <<  std::endl;
}
void test2() {
    Matrix <int, 0> m;
    for (auto i = 0 ; i < 10 ; i++){
    m[i][i] = i;
    m[i][9-i] = 9-i;
	}
    for (auto c: m) {
		int i;
		int j;
		int value;
    std::tie(i, j, value) = c;
		std::cout << "i = " <<  i <<
                    " j = "<<  j <<
                    " value = " << value << std::endl;
	}
}
void test3() {
    Matrix <int, -1> m;
    ((m[100][100] = 314) = 0) = 217;
  std::cout << m[100][100] << std::endl;
  std::cout << m[10000][100000] << std::endl;
}
void test_chess() {
    const int value = -1;
    int size = 10;
    Matrix <int, value> m;
    int value_iter = 0;
    for(int i=0; i<size; ++i) {
        for(int j= i%2; j<size; j+=2) {
            m[i][j] = value;
            ++value_iter;
        }
    }
    std::cout <<"value iterations: " << value_iter << std::endl;
    std::cout <<"size: " << m.size() << std::endl;

    for(int i=0; i<size; ++i) {
        for(int j= 0; j<size; ++j) {
            std::cout << m[i][j]  << " " ;
        }
        std::cout << std::endl;
    }
}
int main() {
    test_from_otus();
    test1();
    test2();
    test3();
    test_chess();
}
