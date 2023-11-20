#ifndef CONJUGATEGRADIENTOMP_H
#define CONJUGATEGRADIENTOMP_H

#include <vector>
#include <omp.h>

#include "../IterativeSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Ops/omp/DVOpsOMP.h"
#include "../../Residuals/ResidualsOMP.h"

template<typename Matrix, typename Vector>
class ConjugateGradientOMP: public IterativeSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        double alpha(const Matrix& A, const Vector& r, const Vector& p) const;
        
        double beta(const Vector& r, const Vector& rPlus1) const;

};

template<>
class ConjugateGradientOMP<DenseMatrix, DenseVector>: public IterativeSolver<DenseMatrix, DenseVector>{

    public:

        static ConjugateGradientOMP<DenseMatrix, DenseVector>& getInstance(){
            static ConjugateGradientOMP<DenseMatrix, DenseVector> instance;
            return instance;
        }

        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r, const DenseVector& p) const;
        
        double beta(const DenseVector& r, const DenseVector& rPlus1) const;

    private:
        ConjugateGradientOMP(){}
        ~ConjugateGradientOMP(){}
        ConjugateGradientOMP(const ConjugateGradientOMP<DenseMatrix, DenseVector>&) = delete;
        ConjugateGradientOMP<DenseMatrix, DenseVector>& operator=(const ConjugateGradientOMP<DenseMatrix, DenseVector>&) = delete;

};

#endif