#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Ops/serial/DVOps.h"

namespace py = pybind11;

template<typename Matrix, typename Vector>
void dvops_submodule_binding(py::module handle, std::string type){

    std::string name_DVOps = std::string("DVOps") + type;
    using Class = DVOps<Matrix, Vector>;
    py::class_<Class>(handle, name_DVOps)
    .def("elemMult", &DVOps<Matrix, Vector>::elemMult)
    .def("elemMult", &DVOps<Matrix, Vector>::elemAdd)
    .def("elemSub", &DVOps<Matrix, Vector>::elemSub)
    .def("elemDiv", &DVOps<Matrix, Vector>::elemDiv)
    .def("scalarMult", &DVOps<Matrix, Vector>::scalarMult)
    .def("norm", &DVOps<Matrix, Vector>::norm)
    .def("dot", &DVOps<Matrix, Vector>::dot)
    .def("vecSum", &DVOps<Matrix, Vector>::vecSum);

}