#include "vector.h"

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