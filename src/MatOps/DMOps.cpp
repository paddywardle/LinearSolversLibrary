#include "DMOps.h"

DenseMatrix DMOps::matMul(const DenseMatrix& matA, const DenseMatrix& matB) {

    int matARows = matA.numRows();
    int matACols = matA.numCols();

    int matBRows = matB.numRows();
    int matBCols = matB.numCols();

    if (matACols != matBRows){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    const std::vector<double>& matAData = matA.getData();
    const std::vector<double>& matBData = matB.getData();

    // needs to be a vector of vectors
    std::vector<std::vector<double>>resultMat (matARows,std::vector<double>(matBCols,0));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            for (int k=0; k<matACols; k++){
                // make this look prettier (make sure it's correct)
                resultMat[i][j] += matAData[i*matACols+k]*matBData[k*matBCols+j];
            }
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseMatrix(matARows, matBCols, resultMat);
}