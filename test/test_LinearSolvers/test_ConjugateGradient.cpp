
#include <gtest/gtest.h>
#include <vector>

#include "../../src/Matrix/DenseMatrix.h"
#include "../../src/Vector/DenseVector.h"
#include "../../src/LinearSolvers/ConjugateGradient.h"

TEST(ConjugateGradient, Alpha) {

    std::vector<std::vector<double>> matData{{1, 2}, {3, 4}};
    std::vector<double> vecData{1,2};

    DenseMatrix mat(matData);
    DenseVector vec(vecData);

    double x = ConjugateGradient::alpha(mat, vec, vec);

    EXPECT_NEAR(x, 0.185185185, 1e-5);
}

TEST(ConjugateGradient, Beta) {

    std::vector<std::vector<double>> matData{{1, 2}, {3, 4}};
    std::vector<double> vecData{1,2};

    DenseVector r({1, 2});
    DenseVector rPlus1({3, 4});

    double x = ConjugateGradient::beta(r, rPlus1);

    EXPECT_EQ(x, 5);
}

TEST(ConjugateGradient, Solver) {

    DenseMatrix A({{5,2,1,0,0,0,0},
                {2,6,2,1,0,0,0},
                {1,2,7,2,1,0,0},
                {0,1,2,8,2,1,0},
                {0,0,1,2,9,2,1},
                {0,0,0,1,2,10,2},
                {0,0,0,0,1,2,11}});

    DenseVector b({1,2,3,4,5,6,7});

    DenseVector x = ConjugateGradient::solver(A, b);

    EXPECT_NEAR(x(0), 0.08082308, 1e-5);
    EXPECT_NEAR(x(1), 0.17884866, 1e-5);
    EXPECT_NEAR(x(2), 0.23818728, 1e-5);
    EXPECT_NEAR(x(3), 0.28888732, 1e-5);
    EXPECT_NEAR(x(4), 0.31639404, 1e-5);
    EXPECT_NEAR(x(5), 0.40089018, 1e-5);
    EXPECT_NEAR(x(6), 0.53471142, 1e-5);
}