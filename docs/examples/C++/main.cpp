#include "main.h"

int main(){
    try {
        std::string matrix_path = "files/Ax.txt";
        std::string vector_path = "files/bx.txt";

        std::vector<std::vector<double>> Ax = read_matrix(matrix_path);
        std::vector<double> bx = read_vector(vector_path);

        DenseMatrix A(Ax);

        DenseVector b(bx);

        DenseVector x = ConjugateGradient<DenseMatrix, DenseVector>::getInstance().solver(A, b);
        std::cout<<x(0)<<"\n";

    }
    catch (const DenseMatrixExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
    catch (const DenseVectorExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
}
