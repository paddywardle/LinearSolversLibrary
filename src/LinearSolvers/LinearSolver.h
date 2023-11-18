#ifndef LINEARSOLVER_H
#define LINEARSOLVER_H

template<typename Matrix, typename Vector>
class LinearSolver{

    public:

        ~LinearSolver() = default;

        virtual Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts=200, const double tol=1e-5) const=0;
        
};

#endif