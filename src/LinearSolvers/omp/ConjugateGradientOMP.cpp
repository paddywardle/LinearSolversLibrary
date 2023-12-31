#include "ConjugateGradientOMP.h"

DenseVector ConjugateGradientOMP<DenseMatrix, DenseVector>::solver(const DenseMatrix& A, const DenseVector& b, DenseVector x, const int maxIts, const double tol) const{

    ResidualsOMP<DenseMatrix, DenseVector>& Residual=ResidualsOMP<DenseMatrix, DenseVector>::getInstance();
    VecOpsOMP<DenseMatrix, DenseVector>& Ops=VecOpsOMP<DenseMatrix, DenseVector>::getInstance();

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }
    
    DenseVector r = Residual.residual(A, b, x);
    DenseVector rPlus1 = r;
    DenseVector p = r;

    double res = 0;
    double alp = 0;
    double bet = 0;

    for (int i=0; i<maxIts; i++){

        // line search step value
        alp = ConjugateGradientOMP::alpha(A, r, p);
        
        // new x and r based on p
        x = Ops.elemAdd(x, Ops.scalarMult(p, alp));
        rPlus1 = Ops.elemSub(r, Ops.scalarMult(Ops.matVecMul(A, p), alp));

        // calculate beta
        bet = ConjugateGradientOMP::beta(r, rPlus1);

        // updated x and r
        p = Ops.elemAdd(rPlus1, Ops.scalarMult(p, bet));
        
        r = rPlus1;
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

double ConjugateGradientOMP<DenseMatrix, DenseVector>::alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p) const{

    VecOpsOMP<DenseMatrix, DenseVector>& Ops=VecOpsOMP<DenseMatrix, DenseVector>::getInstance();

    // alpha = dot(r, r)/ p^T A p
    DenseVector pADen = Ops.vecMatMul(p, A);
    double alphaNum = Ops.dot(r, r);
    double alphaDen = Ops.dot(pADen,p);
    
    return alphaNum/alphaDen;

}

double ConjugateGradientOMP<DenseMatrix, DenseVector>::beta(const DenseVector& r, const DenseVector& rPlus1) const{

    VecOpsOMP<DenseMatrix, DenseVector>& Ops=VecOpsOMP<DenseMatrix, DenseVector>::getInstance();

    double betaNum = Ops.dot(rPlus1, rPlus1);
    double betaDen = Ops.dot(r, r);

    return betaNum/betaDen;

}