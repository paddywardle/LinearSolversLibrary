#include <gtest/gtest.h>
#include <vector>

#include "../src/Matrix/DenseMatrix.h"
#include "../src/Vector/DenseVector.h"
#include "../src/VecOps/DVOps.h"
#include "../src/LinearSolvers/GaussSeidel.h"

TEST(GaussSeidel, Residual) {
    
    double res = GaussSeidel::residual({1,2,3}, {4,5,6});

    EXPECT_EQ(res, 9);
}