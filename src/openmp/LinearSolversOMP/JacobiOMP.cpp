#include "JacobiOMP.h"

DenseVector JacobiOMP::solver(const DenseMatrix& A, DenseVector& b, DenseVector x, int maxIts, double tol){

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }

    double res = 0;

    for (int i=0; i<maxIts; i++){

        JacobiOMP::forwardSweep(A, b, x);
        JacobiOMP::backwardSweep(A, b, x);

        res = ResidualsOMP::L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }
    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

void JacobiOMP::forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    const DenseVector xCurr(x.getData());

    #pragma omp parallel for
    for (int i=0; i<ARows; i++){
        double uNew = b(i);
        for (int j=0; j<ACols; j++){
            if (j!=i){
                uNew -= A(i,j) * xCurr(j);
            }
        }
        x(i) = uNew / A(i,i);
    }
}

void JacobiOMP::backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    const DenseVector xCurr(x.getData());

    #pragma omp parallel for
    for (int i=ARows-1; i>=0; i--){
        double uNew = b(i);
        for (int j=ACols-1; j>=0; j--){
            if (j!=i){
                uNew -= A(i,j) * xCurr(j);
            }
        }
        x(i) = uNew / A(i,i);
    }
}
