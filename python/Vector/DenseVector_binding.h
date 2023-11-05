#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

#include "../../src/Vector/DenseVector.h"

namespace py = pybind11;

void matrix_submodule_binding(py::module handle){

    handle.doc() = "This is the docs.";
    
    py::class_<DenseVector>(handle, "DenseVector")
    .def(py::init<std::vector<double>>())
    .def("getLen",  &DenseVector::getLen)
    .def("getData",  &DenseVector::getData)
    .def("__str__", [](const DenseVector& vec){
        std::ostringstream ss;
        ss<<vec;
        return ss.str();
    })
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