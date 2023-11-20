#include "JacobiOMP.h"

DenseVector JacobiOMP<DenseMatrix, DenseVector>::solver(const DenseMatrix& A, const DenseVector& b, DenseVector x, const int maxIts, const double tol) const{

    ResidualsOMP<DenseMatrix, DenseVector>& Residual=ResidualsOMP<DenseMatrix, DenseVector>::getInstance();

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }

    double res = 0;

    for (int i=0; i<maxIts; i++){

        JacobiOMP<DenseMatrix, DenseVector>::forwardSweep(A, b, x);
        JacobiOMP<DenseMatrix, DenseVector>::backwardSweep(A, b, x);

        res = Residual.L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }
    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

void JacobiOMP<DenseMatrix, DenseVector>::forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const{

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

void JacobiOMP<DenseMatrix, DenseVector>::backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const{

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