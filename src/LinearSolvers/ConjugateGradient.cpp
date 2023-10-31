#include "ConjugateGradient.h"

DenseVector ConjugateGradient::solver(const DenseMatrix& A, DenseVector& b, int maxIts, double tol){

    DenseVector x(std::vector<double>(b.getLen(), 0));

    double res = 0;

    for (int i=0; i<maxIts; i++){

        res = Residuals::L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }
    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

double ConjugateGradient::alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p){
    
}

double ConjugateGradient::beta(const DenseVector& r, const DenseVector& rPlus1){

}