#include "GaussianElimination.h"

DenseVector GaussianElimination::solver(DenseMatrix& A, DenseVector& b){
    
    elimination(A, b);

    return backsub(A, b);
    
}

void GaussianElimination::elimination(DenseMatrix& A, DenseVector& b){

    int ARows = A.numRows();
    int ACols = A.numCols();
    int bLen = b.getLen();

    for (int i=0; i<ARows-2; i++){
        for (int j=i; j<ARows-1; j++){
            double ratio = A(j,i) / A(i,i);
            for (int k=i; k<ACols-1; k++){
                A(j,k) -= ratio*A(i,k);
                b(j) -= ratio*b(i);
            }
        }
    }
}

DenseVector GaussianElimination::backsub(DenseMatrix& Aaug, DenseVector& baug){

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