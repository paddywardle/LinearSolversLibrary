#ifndef DIRECTSOLVER_H
#define DIRECTSOLVER_H

template<typename Matrix, typename Vector>
class DirectSolver{

    public:

        // direct solver
        virtual Vector solver(Matrix& A, Vector& b) const=0;

};

#endif