#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Ops/serial/MatOps.h"

namespace py = pybind11;

template<typename Matrix>
void declareMatOps(py::module handle){
    
    using Class = MatOps<Matrix>;
    py::class_<Class>(handle, "MatOps")
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("matMul", &Class::elemMult)
    .def("elemMult", &Class::elemAdd)
    .def("elemSub", &Class::elemSub)
    .def("elemDiv", &Class::elemDiv)
    .def("scalarMult", &Class::scalarMult)
    .def("zeros", &Class::zeros)
    .def("ones", &Class::ones);
}