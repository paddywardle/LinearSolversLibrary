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

    //pybind11::return_value_policy::reference_internal makes it so that the objects lifetime is managed by C++ rather than python
    std::string GS = std::string("GS") + type;
    using Class_GS = GaussSeidel<Matrix, Vector>;
    py::class_<Class_GS>(solvers, GS.c_str())
    .def_static("getInstance", &Class_GS::getInstance, pybind11::return_value_policy::reference_internal)
    .def("solver", &Class_GS::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    std::string Jac = std::string("Jac") + type;
    using Class_Jac = Jacobi<Matrix, Vector>;
    py::class_<Class_Jac>(solvers, Jac.c_str())
    .def_static("getInstance", &Class_Jac::getInstance, pybind11::return_value_policy::reference_internal)
    .def("solver", &Class_Jac::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    std::string CG = std::string("CG") + type;
    using Class_CG = ConjugateGradient<Matrix, Vector>;
    py::class_<Class_CG>(solvers, CG.c_str())
    .def_static("getInstance", &Class_CG::getInstance, pybind11::return_value_policy::reference_internal)
    .def("solver", &Class_CG::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    std::string SD = std::string("SD") + type;
    using Class_SD = SteepestDescent<Matrix, Vector>;
    py::class_<Class_SD>(solvers, SD.c_str())
    .def_static("getInstance", &Class_SD::getInstance, pybind11::return_value_policy::reference_internal)
    .def("solver", &Class_SD::solver, py::arg("A"), py::arg("b"), py::arg("x") = DenseVector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

    std::string GE = std::string("GE") + type;
    using Class_GE = GaussianElimination<Matrix, Vector>;
    py::class_<Class_GE>(solvers, GE.c_str())
    .def_static("getInstance", &Class_GE::getInstance, pybind11::return_value_policy::reference_internal)
    .def("solver", &Class_GE::solver, py::arg("A"), py::arg("b"));


}