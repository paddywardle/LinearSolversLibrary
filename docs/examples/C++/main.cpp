#include "main.h"

int main(){
    try {
        std::string matrix_path = "files/Ax.txt";
        std::string vector_path = "files/bx.txt";

        std::vector<std::vector<double>> Ax = read_matrix(matrix_path);
        std::vector<double> bx = read_vector(vector_path);

        DenseMatrix A(Ax);

        DenseVector b(bx);

        std::cout<<b<<"\n";

        DenseVector x = GaussSeidelOMP::solver(A, b);
        std::cout<<x<<"\n";

    }
    catch (const DenseMatrixExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
    catch (const DenseVectorExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
}
