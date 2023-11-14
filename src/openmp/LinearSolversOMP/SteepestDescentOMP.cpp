#include "SteepestDescentOMP.h"

DenseVector SteepestDescentOMP::solver(const DenseMatrix& A, DenseVector& b, DenseVector x, int maxIts, double tol){

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }

    DenseVector r = ResidualsOMP::residual(A, b, x);
    DenseVector alphaR;
    double res = 0;
    double alp = 0;

    for (int i=0; i<maxIts; i++){

        // line search step value
        alp = SteepestDescentOMP::alpha(A, r);

        alphaR = DVOpsOMP::scalarMult(r, alp);

        // updated x and r
        x = DVOpsOMP::elemAdd(x, alphaR).getData();
        r = ResidualsOMP::residual(A, b, x);
        
        // new residual
        res = ResidualsOMP::L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }

    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

double SteepestDescentOMP::alpha(const DenseMatrix& A, const DenseVector& r){

    // alpha = dot(r, r)/ r^T A r
    DenseVector rADen = DVOpsOMP::DVMOps::vecMatMul(r, A);
    double alphaNum = DVOpsOMP::dot(r, r);
    double alphaDen = DVOpsOMP::dot(rADen,r);
    
    return alphaNum/alphaDen;

}