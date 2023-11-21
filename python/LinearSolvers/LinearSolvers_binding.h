#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/LinearSolvers/serial/GaussSeidel.h"
#include "../../src/LinearSolvers/serial/Jacobi.h"
#include "../../src/LinearSolvers/serial/SteepestDescent.h"
#include "../../src/LinearSolvers/serial/ConjugateGradient.h"
#include "../../src/LinearSolvers/serial/GaussianElimination.h"
#include "../../src/Vector/DenseVector.h"

namespace py = pybind11;

template<typename Matrix, typename Vector>
void solvers_submodule_binding(py::module handle, std::string type){
    
    auto solvers = handle.def_submodule("Solvers");

    std::string GS = std::string("GaussSeidel") + type;
    using Class_GS = GaussSeidel<Matrix, Vector>;
    py::class_<Class_GS>(solvers, GS)
    .def("getInstance", &Class_GS::getInstance)
    .def("solver", &Class_GS::getInstance.solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    std::string Jac = std::string("Jacobi") + type;
    using Class_Jac = Jacobi<Matrix, Vector>;
    py::class_<Class_Jac>(solvers, Jac)
    .def("getInstance", &Class_Jac::getInstance)
    .def("solver", &Class_Jac::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    std::string CG = std::string("ConjugateGradient") + type;
    using Class_CG = ConjugateGradient<Matrix, Vector>;
    py::class_<Class_CG>(solvers, CG)
    .def("getInstance", &Class_CG::getInstance)
    .def("solver", &Class_CG::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    std::string SD = std::string("SteepestDescent") + type;
    using Class_SD = SteepestDescent<Matrix, Vector>;
    py::class_<Class_SD>(solvers, SD)
    .def("getInstance", &Class_SD::getInstance)
    .def("solver", &Class_SD::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    // std::string GE = std::string("GaussianElimination") + type;
    // using Class_GE = GaussianElimination<Matrix, Vector>;
    // py::class_<Class_GE>(solvers, GE)
    // .def("getInstance", &Class_GE::getInstance)
    // .def("solver", &Class_GE::solver, py::arg("A"), py::arg("b"));


}