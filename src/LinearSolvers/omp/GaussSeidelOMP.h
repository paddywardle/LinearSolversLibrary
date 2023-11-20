#ifndef GAUSSSEIDELOMP_H
#define GAUSSSEIDELOMP_H

#include <vector>
#include <omp.h>

#include "../FixedPointSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Residuals/ResidualsOMP.h"

template<typename Matrix, typename Vector>
class GaussSeidelOMP : public FixedPointSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        void forwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

        void backwardSweep(const Matrix& A, const Vector& b, Vector& x) const override;

};

template<>
class GaussSeidelOMP<DenseMatrix, DenseVector> : public FixedPointSolver<DenseMatrix, DenseVector>{

    public:

        static GaussSeidelOMP<DenseMatrix, DenseVector>& getInstance(){
            static GaussSeidelOMP<DenseMatrix, DenseVector> instance;
            return instance;
        }

        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        void forwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

        void backwardSweep(const DenseMatrix& A, const DenseVector& b, DenseVector& x) const override;

    private:
        GaussSeidelOMP(){}
        ~GaussSeidelOMP(){}
        GaussSeidelOMP(const GaussSeidelOMP<DenseMatrix, DenseVector>&) = delete;
        GaussSeidelOMP<DenseMatrix, DenseVector>& operator=(const GaussSeidelOMP<DenseMatrix, DenseVector>&) = delete;

};

#endif