#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../../src/Residuals/Residuals.h"

namespace py = pybind11;

void res_submodule_binding(py::module handle){
    
    auto Res = handle.def_submodule("Residuals");
    Res.def("residual", &Residuals::residual);
    Res.def("L1", &Residuals::L1MatMul);
}