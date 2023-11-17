#include "SteepestDescent.h"

DenseVector& SteepestDescent<DenseMatrix, DenseVector>::solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const{

    if (x.getData().empty()){
        DenseVector x0(std::vector<double>(b.getLen(), 0));
        x = x0;
    }

    DenseVector r = Residuals::residual(A, b, x);
    DenseVector alphaR;
    double res = 0;
    double alp = 0;

    for (int i=0; i<maxIts; i++){

        // line search step value
        alp = SteepestDescent<DenseMatrix, DenseVector>::alpha(A, r);

        alphaR = DVOps::scalarMult(r, alp);

        // updated x and r
        x = DVOps::elemAdd(x, alphaR).getData();
        r = Residuals::residual(A, b, x);
        
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

double SteepestDescent<DenseMatrix, DenseVector>::alpha(const DenseMatrix& A, const DenseVector& r) const{

    // alpha = dot(r, r)/ r^T A r
    DenseVector rADen = DVOps::DVMOps::vecMatMul(r, A);
    double alphaNum = DVOps::dot(r, r);
    double alphaDen = DVOps::dot(rADen,r);
    
    return alphaNum/alphaDen;

}