#ifndef ITERATIVESOLVER_H
#define ITERATIVESOLVER_H

template<typename Matrix, typename Vector>
class IterativeSolver{

    public:

        // iterative solver
        virtual Vector solver(const Matrix& A, const Vector& b, Vector x, const int maxIts=200, const double tol=1e-5) const=0;

};

#endif