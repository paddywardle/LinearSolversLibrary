#include "iterativeSolvers.h"

template<typename IterativeSolver, typename Vector>
void declareIterativeSolvers(py::module solvers, std::string solverName){
    
    using Class = IterativeSolver;
    py::class_<Class, std::shared_ptr<Class>>(solvers, solverName.c_str())
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("solver", &Class::solver, py::arg("A"), py::arg("b"), py::arg("x") = Vector(), py::arg("maxIts")=200, py::arg("tol")=1e-5);

}
