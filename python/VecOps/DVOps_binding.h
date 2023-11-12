#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../src/serial/VecOps/DVOps.h"

namespace py = pybind11;

void dvops_submodule_binding(py::module handle){
    
    auto DVOps = handle.def_submodule("DVOps");
    DVOps.def("elemMult", &DVOps::elemMult);
    DVOps.def("elemMult", &DVOps::elemAdd);
    DVOps.def("elemSub", &DVOps::elemSub);
    DVOps.def("elemDiv", &DVOps::elemDiv);
    DVOps.def("scalarMult", &DVOps::scalarMult);
    DVOps.def("norm", &DVOps::norm);
    DVOps.def("dot", &DVOps::dot);
    DVOps.def("vecSum", &DVOps::vecSum);

    auto DVMOps = DVOps.def_submodule("DVMOps");
    DVMOps.def("matVecMul", &DVOps::DVMOps::matVecMul);
    DVMOps.def("vecMatMul", &DVOps::DVMOps::vecMatMul);

}