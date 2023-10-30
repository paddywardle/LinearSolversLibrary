#include "GaussSeidel.h"

DenseVector GaussSeidel::solver(const DenseMatrix& A, DenseVector& b, int maxIts, double tol){

    std::vector<double> x(b.getLen(), 0);

    double res = 0;

    for (int i=0; i<maxIts; i++){

        GaussSeidel::forwardSweep(A, b, x);
        GaussSeidel::backwardSweep(A, b, x);

        res = GaussSeidel::residual(A, b, DenseVector(x));

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return DenseVector(x);
        }
    }
    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return DenseVector(x);
}

double GaussSeidel::residual(const DenseMatrix& A, const DenseVector& b, const DenseVector& x){

    // norm(b - A@x)
    DenseVector sub = DVOps::elemSub(b, DVOps::DVMOps::matMul(A,x));
    return DVOps::norm(sub, 1.0);

}

void GaussSeidel::forwardSweep(const DenseMatrix& A, const DenseVector& b, std::vector<double>& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    const std::vector<double>& AData = A.getData();
    const std::vector<double>& bData = b.getData();

    for (int i=0; i<ARows; i++){
        double uNew = bData[i];
        for (int j=0; j<ACols; j++){
            if (j!=i){
                uNew -= AData[i*ACols +j] * x[j];
            }
        }
        x[i] = uNew / AData[i*ACols+i];
    }

}

void GaussSeidel::backwardSweep(const DenseMatrix& A, const DenseVector& b, std::vector<double>& x){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    const std::vector<double>& AData = A.getData();
    const std::vector<double>& bData = b.getData();

    for (int i=ARows-1; i<=0; i--){
        double uNew = bData[i];
        for (int j=ACols-1; j<=0; j--){
            if (j!=i){
                uNew -= AData[i*ACols +j] * x[j];
            }
        }
        x[i] = uNew / AData[i*ACols+i];
    }
}
