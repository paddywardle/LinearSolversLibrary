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

TEST(GaussSeidel, Solver) {

    DenseMatrix A({{5,2,1,0,0,0,0},
                {2,6,2,1,0,0,0},
                {1,2,7,2,1,0,0},
                {0,1,2,8,2,1,0},
                {0,0,1,2,9,2,1},
                {0,0,0,1,2,10,2},
                {0,0,0,0,1,2,11}});

    DenseVector b({1,2,3,4,5,6,7});

    DenseVector x = GaussSeidel::solver(A, b, 1000);

    EXPECT_NEAR(x(0), 0.08082308, 1e-5);
    EXPECT_NEAR(x(1), 0.17884866, 1e-5);
    EXPECT_NEAR(x(2), 0.23818728, 1e-5);
    EXPECT_NEAR(x(3), 0.28888732, 1e-5);
    EXPECT_NEAR(x(4), 0.31639404, 1e-5);
    EXPECT_NEAR(x(5), 0.40089018, 1e-5);
    EXPECT_NEAR(x(6), 0.53471142, 1e-5);
}