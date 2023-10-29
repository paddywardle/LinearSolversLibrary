#include "DMOps.h"

DenseMatrix DMOps::matMul(const DenseMatrix& matA, const DenseMatrix& matB) {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

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
    return DenseMatrix(resultMat);
}

DenseMatrix DMOps::elemMult(const DenseMatrix& matA, const DenseMatrix& matB){

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    const std::vector<double>& matAData = matA.getData();
    const std::vector<double>& matBData = matB.getData();

    // needs to be a vector of vectors
    std::vector<std::vector<double>>resultMat (matARows,std::vector<double>(matACols,0));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat[i][j] =  matAData[i*matACols+j] * matBData[i*matBCols+j];
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseMatrix(resultMat);
}

DenseMatrix DMOps::elemAdd(const DenseMatrix& matA, const DenseMatrix& matB){

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    const std::vector<double>& matAData = matA.getData();
    const std::vector<double>& matBData = matB.getData();

    // needs to be a vector of vectors
    std::vector<std::vector<double>>resultMat (matARows,std::vector<double>(matACols,0));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat[i][j] =  matAData[i*matACols+j] + matBData[i*matBCols+j];
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseMatrix(resultMat);
}

DenseMatrix DMOps::elemSub(const DenseMatrix& matA, const DenseMatrix& matB){

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    const std::vector<double>& matAData = matA.getData();
    const std::vector<double>& matBData = matB.getData();

    // needs to be a vector of vectors
    std::vector<std::vector<double>>resultMat (matARows,std::vector<double>(matACols,0));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat[i][j] =  matAData[i*matACols+j] - matBData[i*matBCols+j];
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseMatrix(resultMat);
}

DenseMatrix DMOps::elemDiv(const DenseMatrix& matA, const DenseMatrix& matB){

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    const std::vector<double>& matAData = matA.getData();
    const std::vector<double>& matBData = matB.getData();

    // needs to be a vector of vectors
    std::vector<std::vector<double>>resultMat (matARows,std::vector<double>(matACols,0));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat[i][j] =  matAData[i*matACols+j] / matBData[i*matBCols+j];
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseMatrix(resultMat);
}

DenseMatrix DMOps::scalarMult(const DenseMatrix& matA, const double val) {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const std::vector<double>& matAData = matA.getData();

    // needs to be a vector of vectors
    std::vector<std::vector<double>>resultMat (matARows,std::vector<double>(matACols,0));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){

            resultMat[i][j] = val * matAData[i*matACols+j];
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseMatrix(resultMat);
}