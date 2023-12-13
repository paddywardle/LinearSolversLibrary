#include "../MatOps.h"

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::matMul(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matACols != matBRows){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    std::vector<std::vector<double>> mat(matARows, std::vector<double>(matBCols, 0));

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            for(int k=0; k<matBRows; k++){
                double val = matA(i,k)*matB(k,j);
                if (val != 0.0){
                    mat[i][j] += val;
                }
            }
        }
    }

    SparseMatrix<SparseTypes::IDX> resultMat(mat);

    return resultMat;
}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::elemMult(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    SparseMatrix<SparseTypes::IDX> resultMat = matA;

    // this will only do it one way - what if there is one in matB that isn't in matA
    // And can't just do the same for loop in reverse as that would mean some were done twice!
    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            double val = matA(i,j) * matB(i,j);
            if (val != 0.0){
                resultMat(i,j) = val;
            }
        }
    }

    return resultMat;
}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::elemAdd(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    SparseMatrix<SparseTypes::IDX> resultMat = MatOps<SparseMatrix<SparseTypes::IDX>>::zeros(matARows, matACols);

    // this will only do it one way - what if there is one in matB that isn't in matA
    // And can't just do the same for loop in reverse as that would mean some were done twice!
    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            double val = matA(i,j) + matB(i,j);
            if (val != 0.0){
                resultMat(i,j) = val;
            }
        }
    }
    
    return resultMat;
}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::elemSub(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    SparseMatrix<SparseTypes::IDX> resultMat = MatOps<SparseMatrix<SparseTypes::IDX>>::zeros(matARows, matACols);

    // this will only do it one way - what if there is one in matB that isn't in matA
    // And can't just do the same for loop in reverse as that would mean some were done twice!
    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            double val = matA(i,j) - matB(i,j);
            if (val != 0.0){
                resultMat(i,j) = val;
            }
        }
    }
    
    return resultMat;
}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::elemDiv(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matARows != matBRows && matACols != matBCols){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    SparseMatrix<SparseTypes::IDX> resultMat = MatOps<SparseMatrix<SparseTypes::IDX>>::zeros(matARows, matACols);

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            double val = matA(i,j) / matB(i,j);
            if (val != 0.0){
                resultMat(i,j) = val;
            }
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::scalarMult(const SparseMatrix<SparseTypes::IDX>& matA, const double val) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    SparseMatrix<SparseTypes::IDX> resultMat = MatOps<SparseMatrix<SparseTypes::IDX>>::zeros(matARows, matACols);

    for (int i=0; i<matARows; i++){
        for (int j=0; j<matACols; j++){
            double calc = val * matA(i,j);
            if (calc != 0.0){
                resultMat(i,j) = calc;
            }
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::zeros(const int numRows, const int numCols) const{
    
    return SparseMatrix<SparseTypes::IDX>(std::vector<std::vector<double>>(numRows, std::vector<double>(numCols,0)));

}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::ones(const int numRows, const int numCols) const{
    
    return SparseMatrix<SparseTypes::IDX>(std::vector<std::vector<double>>(numRows, std::vector<double>(numCols,1)));

}