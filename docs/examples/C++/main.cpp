#include "main.h"

int main(){
    try {
        // std::string matrix_path = "files/Ax.txt";
        // std::string vector_path = "files/bx.txt";

        // std::vector<std::vector<double>> Ax = read_matrix(matrix_path);
        // std::vector<double> bx = read_vector(vector_path);

        // SparseVector<SparseTypes::IDX> b(bx);

        // VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>& Ops=VecOps<SparseMatrix<SparseTypes::IDX>, SparseVector<SparseTypes::IDX>>::getInstance();

        // std::cout<<Ops.norm(b)<<" "<<Ops.dot(b,b)<<"\n";

        // MatOps<DenseMatrix>& Ops=MatOps<DenseMatrix>::getInstance();
        // DenseMatrix A(Ax);
        // DenseMatrix Asqr = Ops.matMul(A,A);

        // MatOps<SparseMatrix<SparseTypes::IDX>>& Ops=MatOps<SparseMatrix<SparseTypes::IDX>>::getInstance();
        // SparseMatrix<SparseTypes::IDX> A(Ax);
        // SparseMatrix<SparseTypes::IDX> Asqr = Ops.matMul(A, A);

        SparseVector<SparseTypes::IDX> b({1,0,5,0,2});
        std::unordered_map<int,double> bMap = b.getDataMap();

        double val = b(0);
        std::cout<<val<<"\n";
        
        for (const auto& keyVal:bMap){
            std::cout<<keyVal.first<<" "<<keyVal.second<<"\n";
        }

        std::cout<<"\n";
        b(2)=0;

        bMap = b.getDataMap();

        for (const auto& keyVal:bMap){
            std::cout<<keyVal.first<<" "<<keyVal.second<<"\n";
        }


    }
    catch (const DenseMatrixExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
    catch (const DenseVectorExceptions& e){
        std::cerr<<e.what()<<"\n";
    }
}
