#ifndef FIXEDPOINTSOLVER_H
#define FIXEDPOINTSOLVER_H

#include "LinearSolver.h"

template<typename Matrix, typename Vector>
class FixedPointSolver : public LinearSolver<Matrix, Vector>{

    public:

        ~FixedPointSolver() = default;

        virtual void forwardSweep(const Matrix& A, const Vector& b, Vector& x) const;

        virtual void backwardSweep(const Matrix& A, const Vector& b, Vector& x) const;

};

#endif