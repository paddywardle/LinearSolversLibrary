#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/Ops/serial/DVOps.h"
#include "../../src/Vector/DenseVector.h"
#include "../../src/Matrix/DenseMatrix.h"

namespace py = pybind11;

template<typename Matrix, typename Vector>
void dvops_submodule_binding(py::module handle, std::string type){

    std::string DVOpsName("DVOps");
    DVOpsName = DVOpsName + type;
    using Class = DVOps<Matrix,Vector>;
    py::class_<Class>(handle, DVOpsName.c_str())
    .def_static("getInstance", &DVOps<Matrix,Vector>::getInstance, pybind11::return_value_policy::reference_internal)
    .def("elemMult", &DVOps<DenseMatrix, DenseVector>::elemMult)
    .def("elemMult", &DVOps<DenseMatrix, DenseVector>::elemAdd)
    .def("elemSub", &DVOps<DenseMatrix, DenseVector>::elemSub)
    .def("elemDiv", &DVOps<DenseMatrix, DenseVector>::elemDiv)
    .def("scalarMult", &DVOps<DenseMatrix, DenseVector>::scalarMult)
    .def("norm", &DVOps<DenseMatrix, DenseVector>::norm)
    .def("dot", &DVOps<DenseMatrix, DenseVector>::dot)
    .def("vecSum", &DVOps<DenseMatrix, DenseVector>::vecSum);

}