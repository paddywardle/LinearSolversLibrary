#include "ConjugateGradientOMP.h"

DenseVector ConjugateGradientOMP::solver(const DenseMatrix& A, DenseVector& b, DenseVector x, int maxIts, double tol){

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }


    DenseVector r = ResidualsOMP::residual(A, b, x);
    DenseVector rPlus1 = r;
    DenseVector p = r;

    double res = 0;
    double alp = 0;
    double bet = 0;

    for (int i=0; i<maxIts; i++){

        // line search step value
        alp = ConjugateGradientOMP::alpha(A, r, p);
        
        // new x and r based on p
        x = DVOpsOMP::elemAdd(x, DVOpsOMP::scalarMult(p, alp));
        rPlus1 = DVOpsOMP::elemSub(r, DVOpsOMP::scalarMult(DVOpsOMP::DVMOps::matVecMul(A, p), alp));

        // calculate beta
        bet = ConjugateGradientOMP::beta(r, rPlus1);

        // updated x and r
        p = DVOpsOMP::elemAdd(rPlus1, DVOpsOMP::scalarMult(p, bet));
        
        r = rPlus1;
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

double ConjugateGradientOMP::alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p){
    
    // alpha = dot(r, r)/ p^T A p
    DenseVector pADen = DVOpsOMP::DVMOps::vecMatMul(p, A);
    double alphaNum = DVOpsOMP::dot(r, r);
    double alphaDen = DVOpsOMP::dot(pADen,p);
    
    return alphaNum/alphaDen;

}

double ConjugateGradientOMP::beta(const DenseVector& r, const DenseVector& rPlus1){

    double betaNum = DVOpsOMP::dot(rPlus1, rPlus1);
    double betaDen = DVOpsOMP::dot(r, r);

    return betaNum/betaDen;

}