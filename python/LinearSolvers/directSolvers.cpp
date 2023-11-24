#include "directSolvers.h"

template<typename IterativeSolver>
void declareDirectSolvers(py::module solvers, std::string solverName){
    
    using Class = IterativeSolver;
    py::class_<Class, std::shared_ptr<Class>>(solvers, solverName.c_str())
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("solver", &Class::solver, py::arg("A"), py::arg("b"));

}