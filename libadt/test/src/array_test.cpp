#include <string>
#include <iostream>
#include <typeinfo>
#include <stdexcept>

using namespace std;

#include "MyArray.hpp"

using namespace ADT;

#include "test.hpp"
#include "array_test.hpp"

bool array_test::do_test(void)
{
    ADT::Array<int> aa(3);
    aa[0] = 1;
    aa[1] = 2;
    ADT::Array<int> b = aa;
    // int aa0 = b[0];
    // int aa1 = b[1];
    // int aa2 = b[2];
    Array2D<int> bb(4, 5);
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 5; j++)
	bb[i][j] = 0;
    Matrix<int> c(3, 3);
    c[1][1] = 1;

    return true;
}
