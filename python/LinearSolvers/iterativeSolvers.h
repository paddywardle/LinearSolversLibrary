#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

namespace py = pybind11;

template<typename IterativeSolver, typename Vector>
void declareIterativeSolvers(py::module solvers, std::string solverName){
    
    using Class = IterativeSolver;
    py::class_<Class, std::shared_ptr<Class>>(solvers, solverName.c_str())
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("solver", &Class::solver, py::arg("A"), py::arg("b"), py::arg("x") = Vector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

}
