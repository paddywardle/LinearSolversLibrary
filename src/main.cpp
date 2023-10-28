#include <vector>
#include <iostream>

#include "Matrix/DenseMatrix.h"
#include "MatOps/DMOps.h"
#include "Exceptions/DenseMatrixExceptions.h"

int main(){
    try {
        std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
        std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}, {21,22,23,24}};

        DenseMatrix matA(matAData);
        DenseMatrix matB(matBData);
        DenseMatrix mat = DMOps::matMul(matA, matB);
        std::cout<<mat;
    }
    catch (const DenseMatrixExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
}
