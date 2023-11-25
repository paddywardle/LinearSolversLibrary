#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Ops/serial/VecOps.h"

namespace py = pybind11;

template<typename Matrix, typename Vector>
void declareVecOps(py::module handle){

    using Class = VecOps<Matrix,Vector>;
    py::class_<Class>(handle, "VecOps")
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("elemMult", &Class::elemMult)
    .def("elemMult", &Class::elemAdd)
    .def("elemSub", &Class::elemSub)
    .def("elemDiv", &Class::elemDiv)
    .def("scalarMult", &Class::scalarMult)
    .def("matVecMul", &Class::matVecMul)
    .def("vecMatMul", &Class::vecMatMul)
    .def("zeros", &Class::zeros)
    .def("ones", &Class::ones)
    .def("norm", &Class::norm)
    .def("dot", &Class::dot)
    .def("vecSum", &Class::vecSum);

}