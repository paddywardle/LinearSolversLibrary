#include "linearSolvers.h"

template<typename Matrix, typename Vector>
void declareLinearSolvers(py::module handle){
    
    auto solvers = handle.def_submodule("solvers");

    declareIterativeSolvers<GaussSeidel<Matrix, Vector>, Vector>(solvers, "GS");
    declareIterativeSolvers<Jacobi<Matrix, Vector>, Vector>(solvers, "Jac");
    declareIterativeSolvers<SteepestDescent<Matrix, Vector>, Vector>(solvers, "SD");
    declareIterativeSolvers<ConjugateGradient<Matrix, Vector>, Vector>(solvers, "CG");

    declareDirectSolvers<GaussianElimination<Matrix, Vector>>(solvers, "GE");
    
}