#include "SteepestDescentOMP.h"

DenseVector SteepestDescentOMP<DenseMatrix, DenseVector>::solver(const DenseMatrix& A, const DenseVector& b, DenseVector x, const int maxIts, const double tol) const{

    ResidualsOMP<DenseMatrix, DenseVector>& Residual=ResidualsOMP<DenseMatrix, DenseVector>::getInstance();
    VecOpsOMP<DenseMatrix, DenseVector>& Ops=VecOpsOMP<DenseMatrix, DenseVector>::getInstance();

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }

    DenseVector r = Residual.residual(A, b, x);
    DenseVector alphaR;
    double res = 0;
    double alp = 0;

    for (int i=0; i<maxIts; i++){

        // line search step value
        alp = SteepestDescentOMP<DenseMatrix, DenseVector>::alpha(A, r);

        alphaR = Ops.scalarMult(r, alp);

        // updated x and r
        x = Ops.elemAdd(x, alphaR).getData();
        r = Residual.residual(A, b, x);
        
        // new residual
        res = Residual.L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }

    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

double SteepestDescentOMP<DenseMatrix, DenseVector>::alpha(const DenseMatrix& A, const DenseVector& r) const{

    VecOpsOMP<DenseMatrix, DenseVector>& Ops=VecOpsOMP<DenseMatrix, DenseVector>::getInstance();

    // alpha = dot(r, r)/ r^T A r
    DenseVector rADen = Ops.vecMatMul(r, A);
    double alphaNum = Ops.dot(r, r);
    double alphaDen = Ops.dot(rADen,r);
    
    return alphaNum/alphaDen;

}