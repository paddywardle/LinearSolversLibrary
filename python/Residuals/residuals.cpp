#include "residuals.h"

template<typename Matrix, typename Vector>
void declareResiduals(py::module handle){
    
    using Class = Residuals<Matrix, Vector>;
    py::class_<Class>(handle, "residual")
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("residual", &Class::residual)
    .def("L1", &Class::L1MatMul);
}