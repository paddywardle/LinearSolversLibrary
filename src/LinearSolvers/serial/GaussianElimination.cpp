#include "GaussianElimination.h"

DenseVector GaussianElimination<DenseMatrix, DenseVector>::solver(DenseMatrix& A, DenseVector& b) const{
    
    elimination(A, b);

    return backsub(A, b);
    
}

void GaussianElimination<DenseMatrix, DenseVector>::elimination(DenseMatrix& A, DenseVector& b) const{

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    for (int i=0; i<ARows; i++){
        for (int j=i+1; j<ARows; j++){
            double ratio = A(j,i) / A(i,i);
            for (int k=i; k<ACols; k++){
                A(j,k) = A(j,k) - ratio*A(i,k);
            }
            b(j) = b(j) - ratio*b(i);
        }
    }
}

DenseVector GaussianElimination<DenseMatrix, DenseVector>::backsub(DenseMatrix& Aaug, DenseVector& baug) const{

    int ARows = Aaug.numRows();
    int ACols = Aaug.numCols();
    int bLen = baug.getLen();

    DenseVector x(std::vector<double>(bLen, 0));


    for (int i=ARows-1; i>=0; i--){
        double uNew = baug(i);
        for (int j=ACols-1; j>=0; j--){
            if (j!=i){
                uNew -= Aaug(i,j) * x(j);
            }
        }
        x(i) = uNew / Aaug(i,i);
    }

    return x;
}