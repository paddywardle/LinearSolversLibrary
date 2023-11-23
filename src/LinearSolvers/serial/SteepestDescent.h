#ifndef STEEPESTDESCENT_H
#define STEEPESTDESCENT_H

#include <vector>

#include "../IterativeSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"
#include "../../Ops/serial/DVOps.h"
#include "../../Residuals/Residuals.h"

template<typename Matrix,  typename Vector>
class SteepestDescent : public IterativeSolver<Matrix, Vector>{

    public:

        Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts, const double tol) const override;

        double alpha(const Matrix& A, const Vector& r) const;

};

template<>
class SteepestDescent<DenseMatrix, DenseVector>: public IterativeSolver<DenseMatrix, DenseVector>{
    
    public:

        static SteepestDescent<DenseMatrix, DenseVector>& getInstance(){
            static SteepestDescent<DenseMatrix, DenseVector> instance;
            return instance;
        }

        ~SteepestDescent(){}

        DenseVector solver(const DenseMatrix& A, const DenseVector& b, DenseVector x=DenseVector(), const int maxIts=200, const double tol=1e-5) const override;

        double alpha(const DenseMatrix& A, const DenseVector& r) const;

    private:
        SteepestDescent(){}
        SteepestDescent(const SteepestDescent<DenseMatrix, DenseVector>&) = delete;
        SteepestDescent<DenseMatrix, DenseVector>& operator=(const SteepestDescent<DenseMatrix, DenseVector>&) = delete;

};

#endif