#include "GaussSeidelOMP.h"

DenseVector GaussSeidelOMP::solver(const DenseMatrix& A, DenseVector& b, DenseVector x, int maxIts, double tol){

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }

    double res = 0;

    for (int i=0; i<maxIts; i++){

        GaussSeidelOMP::forwardSweep(A, b, x);
        GaussSeidelOMP::backwardSweep(A, b, x);

        res = Residuals::L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }
    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

void GaussSeidelOMP::forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    for (int i=0; i<ARows; i++){
        double uNew = b(i);

        // this is the only loop that can be parallelised (columns)
        #pragma omp parallel for reduction(-:uNew)
        for (int j=0; j<ACols; j++){
            if (j!=i){
                uNew -= A(i,j) * x(j);
            }
        }
        x(i) = uNew / A(i,i);
    }
}

void GaussSeidelOMP::backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    for (int i=ARows-1; i>=0; i--){
        double uNew = b(i);

        // this is the only loop that can be parallelised (columns)
        #pragma omp parallel for reduction(-:uNew)
        for (int j=ACols-1; j>=0; j--){
            if (j!=i){
                uNew -= A(i,j) * x(j);
            }
        }
        x(i) = uNew / A(i,i);
    }
}
