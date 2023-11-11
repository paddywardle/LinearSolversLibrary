#include "main.h"

int main(){
    try {

        DenseMatrix A({
            {10, 1, 0, 0, 0, 0, 0},
            {1, 11, 1, 0, 0, 0, 0},
            {0, 1, 12, 1, 0, 0, 0},
            {0, 0, 1, 13, 1, 0, 0},
            {0, 0, 0, 1, 14, 1, 0},
            {0, 0, 0, 0, 1, 15, 1},
            {0, 0, 0, 0, 0, 1, 16}
        });

        DenseVector b({1,2,3,4,5,6,7});
        std::cout<<"Jac\n";
        DenseVector x = JacobiOMP::solver(A, b);
        std::cout<<x<<"\n";

    }
    catch (const DenseMatrixExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
    catch (const DenseVectorExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
}
