#include "../../src/Vector/DenseVector.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

void matrix_submodule_binding(py::module handle){

    handle.doc() = "This is the docs.";
    
    py::class_<DenseVector>(handle, "DenseVector")
    .def(py::init<std::vector<double>>())
    .def("getLen",  &DenseVector::getLen)
    .def("getData",  &DenseVector::getData)
    ;
}

// PYBIND11_MODULE(Vector, handle){

//     handle.doc() = "This is the docs.";
    
//     py::class_<DenseVector>(handle, "DenseVector")
//     .def(py::init<std::vector<double>>())
//     .def("getLen",  &DenseVector::getLen)
//     .def("getData",  &DenseVector::getData)
//     ;
// }