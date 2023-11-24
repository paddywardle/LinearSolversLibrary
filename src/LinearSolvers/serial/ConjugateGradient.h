#ifndef CONJUGATEGRADIENT_H
#define CONJUGATEGRADIENT_H

#include <vector>

#include "../IterativeSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Ops/serial/VecOps.h"
#include "../../Residuals/Residuals.h"

template<typename Matrix, typename Vector>
class ConjugateGradient: public IterativeSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        double alpha(const Matrix& A, const Vector& r, const Vector& p) const;
        
        double beta(const Vector& r, const Vector& rPlus1) const;

};

template<>
class ConjugateGradient<DenseMatrix, DenseVector>: public IterativeSolver<DenseMatrix, DenseVector>{

    public:

        static ConjugateGradient<DenseMatrix, DenseVector>& getInstance(){
            static ConjugateGradient<DenseMatrix, DenseVector> instance;
            return instance;
        }

        ~ConjugateGradient(){}

        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p) const;
        
        double beta(const DenseVector& r, const DenseVector& rPlus1) const;

    private:
        ConjugateGradient(){}
        ConjugateGradient(const ConjugateGradient<DenseMatrix, DenseVector>&) = delete;
        ConjugateGradient<DenseMatrix, DenseVector>& operator=(const ConjugateGradient<DenseMatrix, DenseVector>&) = delete;

};

#endif