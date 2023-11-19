#include "DMOps.h"

DenseMatrix DMOps<DenseMatrix>::matMul(const DenseMatrix& matA, const DenseMatrix& matB) const {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matACols != matBRows){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    DenseMatrix resultMat(std::vector<std::vector<double>>(matARows,std::vector<double>(matBCols,0)));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            for (int k=0; k<matACols; k++){
                // make this look prettier (make sure it's correct)
                resultMat(i,j) += matA(i,k)*matB(k,j);
            }
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

DenseMatrix DMOps<DenseMatrix>::elemMult(const DenseMatrix& matA, const DenseMatrix& matB) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    DenseMatrix resultMat(std::vector<std::vector<double>>(matARows,std::vector<double>(matBCols,0)));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat(i,j) =  matA(i,j) * matB(i,j);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

DenseMatrix DMOps<DenseMatrix>::elemAdd(const DenseMatrix& matA, const DenseMatrix& matB) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    DenseMatrix resultMat(std::vector<std::vector<double>>(matARows,std::vector<double>(matBCols,0)));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat(i,j) =  matA(i,j) + matB(i,j);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

DenseMatrix DMOps<DenseMatrix>::elemSub(const DenseMatrix& matA, const DenseMatrix& matB) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    DenseMatrix resultMat(std::vector<std::vector<double>>(matARows,std::vector<double>(matBCols,0)));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat(i,j) =  matA(i,j) - matB(i,j);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

DenseMatrix DMOps<DenseMatrix>::elemDiv(const DenseMatrix& matA, const DenseMatrix& matB) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    DenseMatrix resultMat(std::vector<std::vector<double>>(matARows,std::vector<double>(matBCols,0)));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            resultMat(i,j) =  matA(i,j) / matB(i,j);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

DenseMatrix DMOps<DenseMatrix>::scalarMult(const DenseMatrix& matA, const double val) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    DenseMatrix resultMat(std::vector<std::vector<double>>(matARows,std::vector<double>(matACols,0)));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){

            resultMat(i,j) = val * matA(i,j);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}