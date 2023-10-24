#include <gtest/gtest.h>
#include "../src/Matrix.h"

TEST(BaseMatrixTest, RowsCols) {
    Matrix mat(2, 3);
    EXPECT_EQ(mat.numRows(), 2);
    EXPECT_EQ(mat.numCols(), 3);
}

g++ -c -o test_numRowsCols.o test_numRowsCols.cpp
g++ -o test_program  ./main_test.o ./test_numRowsCols.o -lgtest -lgtest_main -pthread
/usr/bin/ld: ./test_numRowsCols.o: in function `BaseMatrixTest_RowsCols_Test::TestBody()':
test_numRowsCols.cpp:(.text+0x32): undefined reference to `Matrix::Matrix(unsigned long, unsigned long)'
/usr/bin/ld: test_numRowsCols.cpp:(.text+0x45): undefined reference to `Matrix::numRows() const'
/usr/bin/ld: test_numRowsCols.cpp:(.text+0x106): undefined reference to `Matrix::numCols() const'
collect2: error: ld returned 1 exit status
make: *** [Makefile:18: test_program] Error 1