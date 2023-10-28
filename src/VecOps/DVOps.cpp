#include "DVOps.h"

DenseVector DVOps::elemWise(const DenseVector& vecA, const DenseVector& vecB) {

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