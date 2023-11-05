#include "ConjugateGradient.h"

DenseVector ConjugateGradient::solver(const DenseMatrix& A, DenseVector& b, DenseVector x, int maxIts, double tol){

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }

    DenseVector r = Residuals::residual(A, b, x);
    DenseVector rPlus1 = r;
    DenseVector p = r;

    double res = 0;
    double alp = 0;
    double bet = 0;

    for (int i=0; i<maxIts; i++){

        // line search step value
        alp = ConjugateGradient::alpha(A, r, p);
        
        // new x and r based on p
        x = DVOps::elemAdd(x, DVOps::scalarMult(p, alp));
        rPlus1 = DVOps::elemSub(r, DVOps::scalarMult(DVOps::DVMOps::matVecMul(A, p), alp));

        // calculate beta
        bet = ConjugateGradient::beta(r, rPlus1);

        // updated x and r
        p = DVOps::elemAdd(rPlus1, DVOps::scalarMult(p, bet));
        
        r = rPlus1;
        // new residual
        res = Residuals::L1MatMul(A, b, x);

        if (res < tol){
            std::cout<<"Converged in "<<i+1<<" iterations!\n";
            return x;
        }
    }

    std::cout<<"Converged in "<<maxIts<<" iterations!\n";
    return x;
}

double ConjugateGradient::alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p){
    
    // alpha = dot(r, r)/ p^T A p
    DenseVector pADen = DVOps::DVMOps::vecMatMul(p, A);
    double alphaNum = DVOps::dot(r, r);
    double alphaDen = DVOps::dot(pADen,p);
    
    return alphaNum/alphaDen;

}

double ConjugateGradient::beta(const DenseVector& r, const DenseVector& rPlus1){

    double betaNum = DVOps::dot(rPlus1, rPlus1);
    double betaDen = DVOps::dot(r, r);

    return betaNum/betaDen;

}