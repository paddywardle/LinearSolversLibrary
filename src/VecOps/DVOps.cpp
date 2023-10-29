#include "DVOps.h"

DenseVector DVOps::elemMult(const DenseVector& vecA, const DenseVector& vecB) {

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    const std::vector<double>& vecAData = vecA.getData();
    const std::vector<double>& vecBData = vecB.getData();

    // needs to be a vector of vectors
    std::vector<double>resultVec (vecALen, 0);

    for (int i=0; i<vecALen; i++){
        resultVec[i] += vecAData[i] * vecBData[i];
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseVector(resultVec);
}

DenseVector DVOps::elemAdd(const DenseVector& vecA, const DenseVector& vecB) {

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    const std::vector<double>& vecAData = vecA.getData();
    const std::vector<double>& vecBData = vecB.getData();

    // needs to be a vector of vectors
    std::vector<double>resultVec (vecALen, 0);

    for (int i=0; i<vecALen; i++){
        resultVec[i] += vecAData[i] + vecBData[i];
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseVector(resultVec);
}

DenseVector DVOps::elemSub(const DenseVector& vecA, const DenseVector& vecB) {

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    const std::vector<double>& vecAData = vecA.getData();
    const std::vector<double>& vecBData = vecB.getData();

    // needs to be a vector of vectors
    std::vector<double>resultVec (vecALen, 0);

    for (int i=0; i<vecALen; i++){
        resultVec[i] += (vecAData[i] - vecBData[i]);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseVector(resultVec);
}

DenseVector DVOps::elemDiv(const DenseVector& vecA, const DenseVector& vecB) {

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    const std::vector<double>& vecAData = vecA.getData();
    const std::vector<double>& vecBData = vecB.getData();

    // needs to be a vector of vectors
    std::vector<double>resultVec (vecALen, 0);

    for (int i=0; i<vecALen; i++){
        resultVec[i] += (vecAData[i] / vecBData[i]);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseVector(resultVec);
}

DenseVector DVOps::scalarMult(const DenseVector& vecA, const double val) {

    int vecALen = vecA.getLen();

    const std::vector<double>& vecAData = vecA.getData();

    // needs to be a vector of vectors
    std::vector<double>resultVec (vecALen, 0);

    for (int i=0; i<vecALen; i++){
        resultVec[i] += val * vecAData[i];
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseVector(resultVec);
}

double DVOps::norm(const DenseVector& vecA, const double ord) {

    int vecALen = vecA.getLen();

    const std::vector<double>& vecAData = vecA.getData();

    // needs to be a vector of vectors
    double normResult = 0;

    for (int i=0; i<vecALen; i++){
        normResult += pow(abs(vecAData[i]), ord);
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return pow(normResult, 1/ord);
}

double DVOps::dot(const DenseVector& vecA, const DenseVector& vecB) {

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

double DVOps::vecSum(const DenseVector& vec){

    const std::vector<double>& vecData = vec.getData();

    return std::accumulate(vecData.begin(), vecData.end(), 0);

}

DenseVector DVOps::DVMOps::matMul(const DenseMatrix& mat, const DenseVector& vec) {

    const int matRows = mat.numRows();
    const int matCols = mat.numCols();

    const int vecLen = vec.getLen();

    if (matCols != vecLen){
        throw DenseVectorExceptions("Error: Matrix vector dimensions do not match!");
    }

    const std::vector<double>& matData = mat.getData();
    const std::vector<double>& vecData = vec.getData();

    // needs to be a vector of vectors
    std::vector<double> resultVec (matRows, 0);

    for (int i=0; i<matRows; i++){
        for (int j=0; j<matCols; j++){
            // make this look prettier (make sure it's correct)
            resultVec[i] += matData[i*matCols+j]*vecData[j];
        }
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return DenseVector(resultVec);
}