#include "../VecOps.h"

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::elemMult(const SparseVector<SparseTypes::IDX>& vecA, const SparseVector<SparseTypes::IDX>& vecB) const{

    int vecALen = vecA.getLen();
    int vecBLen = vecB.getLen();

    if (vecALen != vecBLen){
        throw DenseVectorExceptions("Error: Vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec = vecA;

    const std::unordered_map<int, double> vecBMap = vecB.getDataMap();

    for (const auto& keyVal: vecBMap){
        resultVec(keyVal.first) *= keyVal.second;
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

    SparseVector<SparseTypes::IDX> resultVec = vecA;

    const std::unordered_map<int, double> vecBMap = vecB.getDataMap();

    double val;
    for (const auto& keyVal: vecBMap){
        val = resultVec(keyVal.first) + keyVal.second;

        if (val == 0.0){
            resultVec.dropIdx(keyVal.first);
            continue;
        }

        resultVec(keyVal.first) = val;
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

    SparseVector<SparseTypes::IDX> resultVec = vecA;

    const std::unordered_map<int, double> vecBMap = vecB.getDataMap();

    double val;
    for (const auto& keyVal: vecBMap){
        val = resultVec(keyVal.first) - keyVal.second;

        if (val == 0.0){
            resultVec.dropIdx(keyVal.first);
            continue;
        }

        resultVec(keyVal.first) = val;
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

    SparseVector<SparseTypes::IDX> resultVec = vecA;

    const std::unordered_map<int, double> vecBMap = vecB.getDataMap();

    for (const auto& keyVal: vecBMap){
        resultVec(keyVal.first) /= keyVal.second;
    }
    // need to actually put it as a vector of vector for the correct initialisation
    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::scalarMult(const SparseVector<SparseTypes::IDX>& vecA, const double val) const{
    
    int vecALen = vecA.getLen();

    if (val == 0.0){
        return VecOps<SparseMatrix<SparseTypes::IDX>,SparseVector<SparseTypes::IDX>>::zeros(vecALen);
    }

    SparseVector<SparseTypes::IDX> resultVec=vecA;

    const std::unordered_map<int,double> vecAMap = vecA.getDataMap();
    for (const auto& keyVal: vecAMap){
        resultVec(keyVal.first) *= val;
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

    const std::unordered_map<int,double> vecAMap=vecA.getDataMap();

    double dotResult = 0;

    for (const auto& keyVal: vecAMap){
        dotResult += keyVal.second * vecB(keyVal.first);
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

    if (vecLen != matRows){
        throw DenseVectorExceptions("Error: Matrix vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec=VecOps<SparseMatrix<SparseTypes::IDX>,SparseVector<SparseTypes::IDX>>::zeros(vecLen);

    const std::unordered_map<std::vector<int>,double,VectorHasher> matMap=mat.getDataMap();
    const std::unordered_map<int,double> vecMap=vec.getDataMap();

    int matRow,matCol,vecIdx;

    for (const auto& matEntry: matMap){
        matRow=matEntry.first[0];
        matCol=matEntry.first[1];
        for (const auto& vecEntry: vecMap){
            vecIdx=vecEntry.first;
            if (matCol == vecIdx){
                resultVec(matRow) += matEntry.second * vecEntry.second;
            }
        }
    }

    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::vecMatMul(const SparseVector<SparseTypes::IDX>& vec, const SparseMatrix<SparseTypes::IDX>& mat) const{

    const int matRows = mat.numRows();
    const int matCols = mat.numCols();

    const int vecLen = vec.getLen();

    if (vecLen != matRows){
        throw DenseVectorExceptions("Error: Matrix vector dimensions do not match!");
    }

    SparseVector<SparseTypes::IDX> resultVec=VecOps<SparseMatrix<SparseTypes::IDX>,SparseVector<SparseTypes::IDX>>::zeros(vecLen);

    const std::unordered_map<std::vector<int>,double,VectorHasher> matMap=mat.getDataMap();
    const std::unordered_map<int,double> vecMap=vec.getDataMap();

    int matRow,matCol,vecIdx;

    for (const auto& vecEntry: vecMap){
        vecIdx=vecEntry.first;
        for (const auto& matEntry: matMap){
            matRow=matEntry.first[0];
            matCol=matEntry.first[1];
            if (vecIdx == matRow){
                resultVec(matCol) += matEntry.second * vecEntry.second;
            }
        }
    }

    return resultVec;
}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>,SparseVector<SparseTypes::IDX>>::zeros(const int len) const{
    
    return SparseVector<SparseTypes::IDX>(std::vector<double>(len,0));

}

SparseVector<SparseTypes::IDX> VecOps<SparseMatrix<SparseTypes::IDX>,SparseVector<SparseTypes::IDX>>::ones(const int len) const{
    
    return SparseVector<SparseTypes::IDX>(std::vector<double>(len,0));

}