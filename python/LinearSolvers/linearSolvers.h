#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/LinearSolvers/serial/GaussSeidel.h"
#include "../../src/LinearSolvers/serial/Jacobi.h"
#include "../../src/LinearSolvers/serial/SteepestDescent.h"
#include "../../src/LinearSolvers/serial/ConjugateGradient.h"
#include "../../src/LinearSolvers/serial/GaussianElimination.h"

#include "directSolvers.h"
#include "iterativeSolvers.h"

namespace py = pybind11;

template<typename Matrix, typename Vector>
void declareLinearSolvers(py::module handle){
    
    auto solvers = handle.def_submodule("solvers");

    declareIterativeSolvers<GaussSeidel<Matrix, Vector>, Vector>(solvers, "GS");
    declareIterativeSolvers<Jacobi<Matrix, Vector>, Vector>(solvers, "Jac");
    declareIterativeSolvers<SteepestDescent<Matrix, Vector>, Vector>(solvers, "SD");
    declareIterativeSolvers<ConjugateGradient<Matrix, Vector>, Vector>(solvers, "CG");

    declareDirectSolvers<GaussianElimination<Matrix, Vector>>(solvers, "GE");
    
}