#include <vector>
#include <iostream>

#include "Matrix/DenseMatrix.h"
#include "MatOps/DMOps.h"
#include "Vector/Vector.h"
#include "VecOps/DVOps.h"
#include "LinearSolvers/GaussSeidel.h"
#include "Exceptions/DenseMatrixExceptions.h"
#include "LinearSolvers/SteepestDescent.h"

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

        DenseMatrix A({{5,2,1,0,0,0,0},
                        {2,6,2,1,0,0,0},
                        {1,2,7,2,1,0,0},
                        {0,1,2,8,2,1,0},
                        {0,0,1,2,9,2,1},
                        {0,0,0,1,2,10,2},
                        {0,0,0,0,1,2,11}});

        DenseVector b({1,2,3,4,5,6,7});

        DenseVector x = SteepestDescent::solver(A, b, 1);
        std::cout<<"hellllllloooooo\n";
        // std::cout<<x.getData()[0]<<"\n";
        // std::cout<<x<<"\n";

    }
    catch (const DenseMatrixExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
}
