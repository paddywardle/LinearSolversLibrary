#include "../MatOps.h"

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::matMul(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matACols != matBRows){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }

    SparseMatrix<SparseTypes::IDX> resultMat = matA;

    std::vector<double> matAData = matA.getData();
    std::vector<double> matBData = matB.getData();

    std::vector<int> matAColIdx = matA.getColIdx();
    std::vector<int> matBColIdx = matB.getColIdx();

    std::vector<int> matARowIdx = matA.getRowIdx();
    std::vector<int> matBRowIdx = matB.getRowIdx();


    // this will only do it one way - what if there is one in matB that isn't in matA
    // And can't just do the same for loop in reverse as that would mean some were done twice!
    for (int i=0; i<matAData.size(); i++){

        auto itColIdx = std::find(matBColIdx.begin(), matBColIdx.end(), matAColIdx[i]);

        if (itColIdx == matBColIdx.end()){
            resultMat(matARowIdx[i], matAColIdx[i]) = 0.0;
        }
        else {
            int colIdx = std::distance(matBColIdx.begin(), itColIdx);
            if (matARowIdx[i] == matBRowIdx[colIdx]){
                resultMat(matARowIdx[i], matAColIdx[i]) = matA(matARowIdx[i], matAColIdx[i]) * matB(matARowIdx[i], matAColIdx[i]);
            }
        }

    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}