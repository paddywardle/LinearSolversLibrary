#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Ops/serial/DMOps.h"

namespace py = pybind11;

template<typename Matrix>
void dmops_submodule_binding(py::module handle, std::string type){
    
    std::string name_DMOps = std::string("DMOps") + type;
    using Class = DMOps<Matrix>;
    py::class_<Class>(handle, name_DMOps)
    .def("matMul", &DMOps<Matrix>::elemMult)
    .def("elemMult", &DMOps<Matrix>::elemAdd)
    .def("elemSub", &DMOps<Matrix>::elemSub)
    .def("elemDiv", &DMOps<Matrix>::elemDiv)
    .def("scalarMult", &DMOps<Matrix>::scalarMult);
}