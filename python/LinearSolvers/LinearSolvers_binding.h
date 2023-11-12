#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../src/serial/LinearSolvers/GaussSeidel.h"
#include "../../src/serial/LinearSolvers/Jacobi.h"
#include "../../src/serial/LinearSolvers/SteepestDescent.h"
#include "../../src/serial/LinearSolvers/ConjugateGradient.h"
#include "../../src/serial/LinearSolvers/GaussianElimination.h"
#include "../../src/Vector/DenseVector.h"

namespace py = pybind11;

void solvers_submodule_binding(py::module handle){
    
    auto solvers = handle.def_submodule("Solvers");
    
    auto GaussSeidel = solvers.def_submodule("GS");
    GaussSeidel.def("solver", &GaussSeidel::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    auto Jacobi = solvers.def_submodule("Jac");
    Jacobi.def("solver", &Jacobi::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    auto SteepestDescent = solvers.def_submodule("SD");
    SteepestDescent.def("solver", &SteepestDescent::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    auto ConjugateGradient = solvers.def_submodule("CG");
    ConjugateGradient.def("solver", &ConjugateGradient::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    auto GaussianElimination = solvers.def_submodule("GE");
    GaussianElimination.def("solver", &GaussianElimination::solver);

}