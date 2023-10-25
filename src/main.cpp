#include "Matrix/DenseMatrix.h"
#include <vector>
#include <iostream>

int main(){

    std::vector<std::vector<double>> matrix{{1, 2},{3,4}};

    DenseMatrix mat(2, 2, matrix);

    std::cout<<mat.getData()[0][0]<<std::endl;
}
