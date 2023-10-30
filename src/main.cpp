#include <vector>
#include <iostream>

#include "Matrix/DenseMatrix.h"
#include "MatOps/DMOps.h"
#include "Vector/Vector.h"
#include "VecOps/DVOps.h"
#include "LinearSolvers/GaussSeidel.h"
#include "Exceptions/DenseMatrixExceptions.h"

int main(){
    try {
        // std::vector<std::vector<double>> matAData{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
        // std::vector<std::vector<double>> matBData{{9,10,11,12}, {13,14,15,16}, {17,18,19,20}, {21,22,23,24}};

        // DenseMatrix matA(matAData);
        // DenseMatrix matB(matBData);
        // DenseMatrix mat = DMOps::matMul(matA, matB);
        // std::cout<<mat;

        // std::vector<double> vecAData{1,2,3,4};
        // std::vector<double> vecBData{9,10,11,12};

        // DenseVector vecA(vecAData);
        // DenseVector vecB(vecBData);

        // DenseVector vec = DVOps::elemMult(vecA, vecB);

        DenseMatrix A({{3, 2},{2, 5}});
        DenseVector b({12, 15});
        std::cout<<A(1,1)<<" "<<b(0)<<"\n";

        b(0) = 5050;
        A(1,1) = 4545;
        
        std::cout<<A(1,1)<<" "<<b(0)<<"\n";
        DenseVector x = GaussSeidel::solver(A, b);

        std::cout<<x<<"\n";

    }
    catch (const DenseMatrixExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
}
