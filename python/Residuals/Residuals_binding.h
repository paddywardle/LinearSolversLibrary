#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Residuals/Residuals.h"

namespace py = pybind11;

template<typename Matrix, typename Vector>
void res_submodule_binding(py::module handle, std::string type){
    
    std::string name_Res = std::string("Residuals") + type;
    using Class = Residuals<Matrix, Vector>;
    py::class_<Class>(handle, name_Res.c_str())
    .def_static("getInstance", &Residuals<Matrix, Vector>::getInstance, pybind11::return_value_policy::reference_internal)
    .def("residual", &Residuals<Matrix, Vector>::residual)
    .def("L1", &Residuals<Matrix, Vector>::L1MatMul);
}