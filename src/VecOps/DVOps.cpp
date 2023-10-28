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