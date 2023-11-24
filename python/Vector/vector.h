#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

#include "../../src/Vector/DenseVector.h"

namespace py = pybind11;

template<typename Vector>
void declareVector(py::module handle){

    handle.doc() = "This is the docs.";
    
    py::class_<Vector>(handle, "vector")
    .def(py::init<std::vector<double>>())
    .def("getLen",  &Vector::getLen)
    .def("getData",  &Vector::getData)
    .def("__str__", [](const Vector& vec){
        std::ostringstream ss;
        ss<<vec;
        return ss.str();
    })
    ;
}