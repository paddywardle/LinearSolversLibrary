#include "VecOpsOMP.h"

DenseVector VecOpsOMP<DenseMatrix, DenseVector>::elemMult(const DenseVector& vecA, const DenseVector& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    DenseVector resultVec(std::vector<double>(vecALen, 0));

    #pragma omp parallel for
    for (int i=0; i<vecALen; i++){
        resultVec(i) += vecA(i) * vecB(i);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

DenseVector VecOpsOMP<DenseMatrix, DenseVector>::elemAdd(const DenseVector& vecA, const DenseVector& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    DenseVector resultVec(std::vector<double>(vecALen, 0));

    #pragma omp parallel for
    for (int i=0; i<vecALen; i++){
        resultVec(i) += vecA(i) + vecB(i);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

DenseVector VecOpsOMP<DenseMatrix, DenseVector>::elemSub(const DenseVector& vecA, const DenseVector& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    DenseVector resultVec(std::vector<double>(vecALen, 0));

    #pragma omp parallel for
    for (int i=0; i<vecALen; i++){
        resultVec(i) += (vecA(i) - vecB(i));
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

DenseVector VecOpsOMP<DenseMatrix, DenseVector>::elemDiv(const DenseVector& vecA, const DenseVector& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    DenseVector resultVec(std::vector<double>(vecALen, 0));

    #pragma omp parallel for
    for (int i=0; i<vecALen; i++){
        resultVec(i) += (vecA(i) / vecB(i));
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

DenseVector VecOpsOMP<DenseMatrix, DenseVector>::scalarMult(const DenseVector& vecA, const double val) const{

    int vecALen = vecA.getLen();

    DenseVector resultVec(std::vector<double>(vecALen, 0));

    #pragma omp parallel for
    for (int i=0; i<vecALen; i++){
        resultVec(i) += val * vecA(i);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

double VecOpsOMP<DenseMatrix, DenseVector>::norm(const DenseVector& vecA, const double ord) const{

    int vecALen = vecA.getLen();

    const std::vector<double>& vecAData = vecA.getData();

    // needs to be a vector of vectors
    double normResult = 0.0;

    #pragma omp parallel for reduction(+:normResult)
    for (int i=0; i<vecALen; i++){
        normResult += pow(fabs(vecAData[i]), ord);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return pow(normResult, 1.0/ord);
}

double VecOpsOMP<DenseMatrix, DenseVector>::dot(const DenseVector& vecA, const DenseVector& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    const std::vector<double>& vecAData = vecA.getData();
    const std::vector<double>& vecBData = vecB.getData();

    // needs to be a vector of vectors
    double dotResult = 0;

    #pragma omp parallel for reduction(+:dotResult)
    for (int i=0; i<vecALen; i++){
        dotResult += vecAData[i] * vecBData[i];
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return dotResult;
}

double VecOpsOMP<DenseMatrix, DenseVector>::vecSum(const DenseVector& vec) const{

    const std::vector<double>& vecData = vec.getData();

    return std::accumulate(vecData.begin(), vecData.end(), 0);

}

DenseVector VecOpsOMP<DenseMatrix, DenseVector>::matVecMul(const DenseMatrix& mat, const DenseVector& vec) const{

    const int matRows = mat.numRows();
    const int matCols = mat.numCols();

    const int vecLen = vec.getLen();

    if (matCols != vecLen){
        throw DenseVectorExceptions("Error: Matrix vector dimensions do not match!");
    }

    DenseVector resultVec(std::vector<double>(matRows, 0));

    #pragma omp parallel for
    for (int i=0; i<matRows; i++){
        for (int j=0; j<matCols; j++){
            // make this look prettier (make sure it's correct)
            resultVec(i) += mat(i,j)*vec(j);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

DenseVector VecOpsOMP<DenseMatrix, DenseVector>::vecMatMul(const DenseVector& vec, const DenseMatrix& mat) const{

    const int matRows = mat.numRows();
    const int matCols = mat.numCols();

    const int vecLen = vec.getLen();

    if (vecLen != matRows){
        throw DenseVectorExceptions("Error: Matrix vector dimensions do not match!");
    }

    DenseVector resultVec(std::vector<double>(matRows, 0));

    #pragma omp parallel for
    for (int i=0; i<matCols; i++){
        for (int j=0; j<matRows; j++){
            // make this look prettier (make sure it's correct)
            resultVec(i) += vec(j)*mat(j,i);
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

DenseVector VecOpsOMP<DenseMatrix,DenseVector>::zeros(const int len) const{
    
    return DenseVector(std::vector<double>(len,0));

}

DenseVector VecOpsOMP<DenseMatrix,DenseVector>::ones(const int len) const{
    
    return DenseVector(std::vector<double>(len,0));

}