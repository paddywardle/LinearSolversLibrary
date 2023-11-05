#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

#include "../../src/Matrix/DenseMatrix.h"

namespace py = pybind11;

void vector_submodule_binding(py::module handle){
    
    py::class_<DenseMatrix>(handle, "DenseMatrix")
    .def(py::init<std::vector<std::vector<double>>>())
    .def("numRows",  &DenseMatrix::numRows)
    .def("numCols", &DenseMatrix::numCols)
    .def("getData",  &DenseMatrix::getData)
    .def("__str__", [](const DenseMatrix& mat){
        std::ostringstream ss;
        ss<<mat;
        return ss.str();
    })
    ;
}

// PYBIND11_MODULE(Matrix, handle){

//     handle.doc() = "This is the docs.";
    
//     py::class_<DenseMatrix>(handle, "DenseMatrix")
//     .def(py::init<std::vector<std::vector<double>>>())
//     .def("numRows",  &DenseMatrix::numRows)
//     .def("numCols", &DenseMatrix::numCols)
//     .def("getData",  &DenseMatrix::getData)
//     ;
// }