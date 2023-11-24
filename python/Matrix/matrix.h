#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>
#include "../../src/Matrix/DenseMatrix.h"

namespace py = pybind11;

template<typename Matrix>
void declareMatrix(py::module handle){
    
    py::class_<Matrix>(handle, "matrix")
    .def(py::init<std::vector<std::vector<double>>>())
    .def("numRows",  &Matrix::numRows)
    .def("numCols", &Matrix::numCols)
    .def("getData",  &Matrix::getData)
    .def("__str__", [](const Matrix& mat){
        std::ostringstream ss;
        ss<<mat;
        return ss.str();
    })
    ;
}