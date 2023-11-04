#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../../src/MatOps/DMOps.h"

namespace py = pybind11;

void dmops_submodule_binding(py::module handle){
    
    auto DMOps = handle.def_submodule("DMOps");
    DMOps.def("matMul", &DMOps::elemMult);
    DMOps.def("elemMult", &DMOps::elemAdd);
    DMOps.def("elemSub", &DMOps::elemSub);
    DMOps.def("elemDiv", &DMOps::elemDiv);
    DMOps.def("scalarMult", &DMOps::scalarMult);
}