#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Ops/serial/DVOps.h"

namespace py = pybind11;

template<typename Matrix, typenamee Vector>
void dvops_submodule_binding(py::module handle, std::string type){

    using Class = DVOps<Matrix, Vector>
    py::class_<Class>(handle, "DVOps")
    .def("elemMult", &DVOps::elemMult)
    .def("elemMult", &DVOps::elemAdd)
    .def("elemSub", &DVOps::elemSub)
    .def("elemDiv", &DVOps::elemDiv)
    .def("scalarMult", &DVOps::scalarMult)
    .def("norm", &DVOps::norm)
    .def("dot", &DVOps::dot)
    .def("vecSum", &DVOps::vecSum);

}