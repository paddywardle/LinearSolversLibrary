#ifndef GAUSSIANELIMINATION_H
#define GAUSSIANELIMINATION_H

#include <vector>

#include "../DirectSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"

template<typename Matrix, typename Vector>
class GaussianElimination : public DirectSolver<Matrix, Vector>{

    public:

        Vector solver(Matrix& A, Vector& b) const override;
            
        void elimination(Matrix& A, Vector& b) const;

        Vector backsub(Matrix& Aaug, Vector& baug) const;

};

template<>
class GaussianElimination<DenseMatrix, DenseVector> : public DirectSolver<DenseMatrix, DenseVector>{

    public:

        static GaussianElimination<DenseMatrix, DenseVector>& getInstance(){
            static GaussianElimination<DenseMatrix, DenseVector> instance;
            return instance;
        }

        ~GaussianElimination(){}
        
        DenseVector solver(DenseMatrix& A, DenseVector& b) const override;

        void elimination(DenseMatrix& A, DenseVector& b) const;

        DenseVector backsub(DenseMatrix& Aaug, DenseVector& baug) const;

    private:
        GaussianElimination(){}
        GaussianElimination(const GaussianElimination<DenseMatrix, DenseVector>&) = delete;
        GaussianElimination<DenseMatrix, DenseVector>& operator=(const GaussianElimination<DenseMatrix, DenseVector>&) = delete;

};

#endif