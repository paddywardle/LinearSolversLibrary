#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Residuals/Residuals.h"

namespace py = pybind11;

template<typename Matrix, typename Vector>
void res_submodule_binding(py::module handle, std::string type){
    
    using Class = Residuals<Matrix, Vector>
    py::class_<Class>(handle, "Residuals")
    .def("residual", &Residuals::residual)
    .def("L1", &Residuals::L1MatMul);
}