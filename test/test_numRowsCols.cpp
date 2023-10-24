#include <gtest/gtest.h>
#include "../src/Matrix.h"

TEST(BaseMatrixTest, RowsCols) {
    Matrix mat(2, 3);
    EXPECT_EQ(mat.numRows(), 2);
    EXPECT_EQ(mat.numCols(), 3);
}