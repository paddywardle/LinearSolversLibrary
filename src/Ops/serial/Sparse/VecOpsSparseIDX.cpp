#include "VecOps.h"

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::elemMult(const SparseVector<SparseTypes::IDX>& vecA, const SparseVector<SparseTypes::IDX>& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec(std::vector<double>(vecALen, 0));

    for (int i=0; i<vecALen; i++){
        resultVec(i) += vecA(i) * vecB(i);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::elemAdd(const SparseVector<SparseTypes::IDX>& vecA, const SparseVector<SparseTypes::IDX>& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec(std::vector<double>(vecALen, 0));

    for (int i=0; i<vecALen; i++){
        resultVec(i) += vecA(i) + vecB(i);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::elemSub(const SparseVector<SparseTypes::IDX>& vecA, const SparseVector<SparseTypes::IDX>& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec(std::vector<double>(vecALen, 0));

    for (int i=0; i<vecALen; i++){
        resultVec(i) += (vecA(i) - vecB(i));
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::elemDiv(const SparseVector<SparseTypes::IDX>& vecA, const SparseVector<SparseTypes::IDX>& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec(std::vector<double>(vecALen, 0));

    for (int i=0; i<vecALen; i++){
        resultVec(i) += (vecA(i) / vecB(i));
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::scalarMult(const SparseVector<SparseTypes::IDX>& vecA, const double val) const{

    int vecALen = vecA.getLen();

    SparseVector<SparseTypes::IDX> resultVec(std::vector<double>(vecALen, 0));

    for (int i=0; i<vecALen; i++){
        resultVec(i) += val * vecA(i);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

double VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::norm(const SparseVector<SparseTypes::IDX>& vecA, const double ord) const{

    int vecALen = vecA.getLen();

    const std::vector<double>& vecAData = vecA.getData();

    // needs to be a vector of vectors
    double normResult = 0.0;

    for (int i=0; i<vecALen; i++){
        normResult += pow(fabs(vecAData[i]), ord);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return pow(normResult, 1.0/ord);
}

double VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::dot(const SparseVector<SparseTypes::IDX>& vecA, const SparseVector<SparseTypes::IDX>& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    const std::vector<double>& vecAData = vecA.getData();
    const std::vector<double>& vecBData = vecB.getData();

    // needs to be a vector of vectors
    double dotResult = 0;

    for (int i=0; i<vecALen; i++){
        dotResult += vecAData[i] * vecBData[i];
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return dotResult;
}

double VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::vecSum(const SparseVector<SparseTypes::IDX>& vec) const{

    const std::vector<double>& vecData = vec.getData();

    return std::accumulate(vecData.begin(), vecData.end(), 0);

}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::matVecMul(const SparseMatrix<SparseTypes::IDX>& mat, const SparseVector<SparseTypes::IDX>& vec) const{

    const int matRows = mat.numRows();
    const int matCols = mat.numCols();

    const int vecLen = vec.getLen();

    if (matCols != vecLen){
        throw DenseVectorExceptions("Error: Matrix vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec(std::vector<double>(matRows, 0));

    for (int i=0; i<matRows; i++){
        for (int j=0; j<matCols; j++){
            // make this look prettier (make sure it's correct)
            resultVec(i) += mat(i,j)*vec(j);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::vecMatMul(const SparseVector<SparseTypes::IDX>& vec, const SparseMatrix<SparseTypes::IDX>& mat) const{

    const int matRows = mat.numRows();
    const int matCols = mat.numCols();

    const int vecLen = vec.getLen();

    if (vecLen != matRows){
        throw DenseVectorExceptions("Error: Matrix vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec(std::vector<double>(matRows, 0));

    for (int i=0; i<matCols; i++){
        for (int j=0; j<matRows; j++){
            // make this look prettier (make sure it's correct)
            resultVec(i) += vec(j)*mat(j,i);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>,SparseVector<SparseTypes::IDX>>::zeros(const int len) const{
    
    return SparseVector<SparseTypes::IDX>(std::vector<double>(len,0));

}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>,SparseVector<SparseTypes::IDX>>::ones(const int len) const{
    
    return SparseVector<SparseTypes::IDX>(std::vector<double>(len,0));

}