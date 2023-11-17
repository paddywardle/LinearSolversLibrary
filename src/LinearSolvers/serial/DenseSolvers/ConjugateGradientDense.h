#ifndef CONJUGATEGRADIENTDENSE_H
#define CONJUGATEGRADIENTDENSE_H

#include "../LinearSolver.h"
#include "../../../Matrix/DenseMatrix.h"
#include "../../../Vector/DenseVector.h"
#include "../../VecOps/DVOps.h"
#include "../../Residuals/Residuals.h"

class ConjugateGradientDense<DenseMatrix, DenseVector>: public LinearSolver<DenseMatrix, DenseVector>{

    public:

        // singleton static method
        static ConjugateGradientDense& getInstance();

        DenseVector& solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts, const double tol) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p) const;
        
        double beta(const DenseVector& r, const DenseVector& rPlus1) const;

    private:

        // private constructor and destructor so an instance can only be created through getInstance
        ConjugateGradientDense() {};
        ~ConjugateGradientDense() {};

        // deleting copy constructor and operator= so that another instance cannot be created (singleton)
        ConjugateGradientDense(const ConjugateGradientDense&) = delete;
        ConjugateGradientDense& operator=(const ConjugateGradientDense&) = delete;

};

#endif