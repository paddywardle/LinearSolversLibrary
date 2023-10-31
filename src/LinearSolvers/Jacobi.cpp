#include "Jacobi.h"

DenseVector Jacobi::solver(const DenseMatrix& A, DenseVector& b, int maxIts, double tol){

    DenseVector x(std::vector<double>(b.getLen(), 0));

    double res = 0;

    for (int i=0; i<maxIts; i++){

        Jacobi::forwardSweep(A, b, x);
        Jacobi::backwardSweep(A, b, x);

        res = Residuals::L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }
    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

void Jacobi::forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    const DenseVector xCurr(x.getData());

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

void Jacobi::backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    const DenseVector xCurr(x.getData());

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
