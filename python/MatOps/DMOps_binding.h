#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Ops/serial/DMOps.h"

namespace py = pybind11;

template<typename Matrix>
void dmops_submodule_binding(py::module handle, std::string type){
    
    using Class = DMOps<Matrix>
    py::class_<Class>(handle, "DVOps")
    .def("matMul", &DMOps::elemMult)
    .def("elemMult", &DMOps::elemAdd)
    .def("elemSub", &DMOps::elemSub)
    .def("elemDiv", &DMOps::elemDiv)
    .def("scalarMult", &DMOps::scalarMult);
}