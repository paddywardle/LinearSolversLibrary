#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <vector>
#include <omp.h>

#include "../DirectSolver.h"
#include "../../Matrix/DenseMatrix.h"
#include "../../Vector/DenseVector.h"

template<typename Matrix, typename Vector>
class GaussianEliminationOMP : public DirectSolver<Matrix, Vector>{

    public:

        Vector solver(Matrix& A, Vector& b) const override;
            
        void elimination(Matrix& A, Vector& b) const;

        Vector backsub(Matrix& Aaug, Vector& baug) const;

};

template<>
class GaussianEliminationOMP<DenseMatrix, DenseVector> : public DirectSolver<DenseMatrix, DenseVector>{

    public:

        static GaussianEliminationOMP<DenseMatrix, DenseVector>& getInstance(){
            static GaussianEliminationOMP<DenseMatrix, DenseVector> instance;
            return instance;
        }

        DenseVector solver(DenseMatrix& A, DenseVector& b) const override;

        void elimination(DenseMatrix& A, DenseVector& b) const;

        DenseVector backsub(DenseMatrix& Aaug, DenseVector& baug) const;

    private:
        GaussianEliminationOMP(){}
        ~GaussianEliminationOMP(){}
        GaussianEliminationOMP(const GaussianEliminationOMP<DenseMatrix, DenseVector>&) = delete;
        GaussianEliminationOMP<DenseMatrix, DenseVector>& operator=(const GaussianEliminationOMP<DenseMatrix, DenseVector>&) = delete;

};

#endif