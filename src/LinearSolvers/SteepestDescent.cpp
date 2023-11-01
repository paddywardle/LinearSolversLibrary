#include "SteepestDescent.h"

DenseVector SteepestDescent::solver(const DenseMatrix& A, DenseVector& b, int maxIts, double tol){

    DenseVector x(std::vector<double>(b.getLen(), 0));
    DenseVector xPlus1 = x;

    DenseVector r = Residuals::residual(A, b, x);
    DenseVector alphaR;
    double res = 0;
    double alp = 0;

    for (int i=0; i<maxIts; i++){

        alp = SteepestDescent::alpha(A, r);

        alphaR = DVOps::scalarMult(r, alp);

        xPlus1 = DVOps::elemAdd(x, alphaR).getData();
        res = Residuals::L1MatMul(A, b, xPlus1);

        // getting a segmentation error (think all the numbers in the data are too big -> overflow)
        // Look at if I should be using a positive definite test case?
        // see if all the parts are returning what I expect
        // look how residuals progress

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }

        x = xPlus1;

    }
    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

double SteepestDescent::alpha(const DenseMatrix& A, const DenseVector& r){

    DenseVector rADen = DVOps::DVMOps::vecMatMul(r, A);
    double alphaNum = DVOps::dot(r, r);
    double alphaDen = DVOps::dot(rADen,r);
    
    return alphaNum/alphaDen;

}