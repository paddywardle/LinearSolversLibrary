#include "../MatOps.h"

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::matMul(const SparseMatrix<SparseTypes::IDX>& matA, const SparseMatrix<SparseTypes::IDX>& matB) const {

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    const int matBRows = matB.numRows();
    const int matBCols = matB.numCols();

    if (matACols != matBRows){
        throw DenseMatrixExceptions("Error: Matrix dimensions do not match!");
    }
    
    std::unordered_map<std::vector<int>,double,VectorHasher> matAMap = matA.getDataMap();
    std::unordered_map<std::vector<int>,double,VectorHasher> matBMap = matB.getDataMap();
    SparseMatrix<SparseTypes::IDX> resultMat=MatOps<SparseMatrix<SparseTypes::IDX>>::zeros(matARows,matACols);

    for (const auto& matAEntry: matAMap){
        const int& matARow = matAEntry.first.front();
        const int& matACol = matAEntry.first.back();

        for (const auto& matBEntry: matBMap){
            const int& matBRow = matBEntry.first.front();
            const int& matBCol = matBEntry.first.back();
            
            if (matACol == matBRow){
                resultMat(matARow, matBCol) += matAEntry.second * matBEntry.second;

            }
        }
    }

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

    std::unordered_map<std::vector<int>,double,VectorHasher> matBMap = matB.getDataMap();

    for (const auto& keyVal: matBMap){
        resultMat(keyVal.first[0], keyVal.first[1]) *= keyVal.second;
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

    SparseMatrix<SparseTypes::IDX> resultMat = matA;

    std::unordered_map<std::vector<int>,double,VectorHasher> matBMap = matB.getDataMap();

    for (const auto& keyVal: matBMap){
        double val = resultMat(keyVal.first[0], keyVal.first[1]) + keyVal.second;

        if (val == 0.0){
            resultMat.dropIdx(keyVal.first);
            continue;
        }

        resultMat(keyVal.first[0], keyVal.first[1]) = val;
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

    SparseMatrix<SparseTypes::IDX> resultMat = matA;

    std::unordered_map<std::vector<int>,double,VectorHasher> matBMap = matB.getDataMap();

    for (const auto& keyVal: matBMap){
        double val = resultMat(keyVal.first[0], keyVal.first[1]) - keyVal.second;

        if (val == 0.0){
            resultMat.dropIdx(keyVal.first);
            continue;
        }

        resultMat(keyVal.first[0], keyVal.first[1]) = val;
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

    SparseMatrix<SparseTypes::IDX> resultMat = matA;

    std::unordered_map<std::vector<int>,double,VectorHasher> matBMap = matB.getDataMap();

    for (const auto& keyVal: matBMap){
        resultMat(keyVal.first[0], keyVal.first[1]) /= keyVal.second;
    }

    // need to actually put it as a vector of vector for the correct initialisation
    return resultMat;
}

SparseMatrix<SparseTypes::IDX> MatOps<SparseMatrix<SparseTypes::IDX>>::scalarMult(const SparseMatrix<SparseTypes::IDX>& matA, const double val) const{

    const int matARows = matA.numRows();
    const int matACols = matA.numCols();

    if (val == 0.0){
        return MatOps<SparseMatrix<SparseTypes::IDX>>::zeros(matARows,matACols);
    }

    SparseMatrix<SparseTypes::IDX> resultMat = matA;

    std::unordered_map<std::vector<int>,double,VectorHasher> matAMap = matA.getDataMap();

    for (const auto& keyVal: matAMap){
        resultMat(keyVal.first[0], keyVal.first[1]) *= val;
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