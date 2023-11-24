#include "vecOps.h"

template<typename Matrix, typename Vector>
void declareVecOps(py::module handle){

    using Class = VecOps<Matrix,Vector>;
    py::class_<Class>(handle, "DVOps")
    .def_static("getInstance", &Class::getInstance, py::return_value_policy::reference)
    .def("elemMult", &Class::elemMult)
    .def("elemMult", &Class::elemAdd)
    .def("elemSub", &Class::elemSub)
    .def("elemDiv", &Class::elemDiv)
    .def("scalarMult", &Class::scalarMult)
    .def("matVecMul", &Class::matVecMul)
    .def("vecMatMul", &Class::vecMatMul)
    .def("norm", &Class::norm)
    .def("dot", &Class::dot)
    .def("vecSum", &Class::vecSum);

}