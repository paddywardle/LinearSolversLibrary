#include "matOps.h"

template<typename Matrix>
void declareMatOps(py::module handle){
    
    using Class = MatOps<Matrix>;
    py::class_<Class>(handle, "DMOps")
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("matMul", &Class::elemMult)
    .def("elemMult", &Class::elemAdd)
    .def("elemSub", &Class::elemSub)
    .def("elemDiv", &Class::elemDiv)
    .def("scalarMult", &Class::scalarMult);
}