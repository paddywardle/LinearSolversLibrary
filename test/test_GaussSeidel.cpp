#include <gtest/gtest.h>
#include <vector>

#include "../src/Matrix/DenseMatrix.h"
#include "../src/Matrix/DenseMatrix.h"
#include "../src/Vector/DenseVector.h"
#include "../src/VecOps/DVOps.h"
#include "../src/LinearSolvers/GaussSeidel.h"

TEST(GaussSeidel, Residual) {

    DenseMatrix mat({{1, 2, 3}, {4, 5.5, 6}, {7, 8, 9}});
    DenseVector vec({1, 2.43, 3});
    
    double res = GaussSeidel::residual(mat, vec, vec);

    EXPECT_EQ(res, 97.235);
}