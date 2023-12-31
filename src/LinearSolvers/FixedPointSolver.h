#ifndef FIXEDPOINTSOLVER_H
#define FIXEDPOINTSOLVER_H

#include "IterativeSolver.h"

template<typename Matrix, typename Vector>
class FixedPointSolver : public IterativeSolver<Matrix, Vector>{

    public:

        ~FixedPointSolver() = default;

        virtual void forwardSweep(const Matrix& A, const Vector& b, Vector& x) const=0;

        virtual void backwardSweep(const Matrix& A, const Vector& b, Vector& x) const=0;

};

#endif