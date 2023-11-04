#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Matrix/DenseMatrix_binding.cpp"
#include "Vector/DenseVector_binding.cpp"
#include "VecOps/DVOps_binding.cpp"
#include "MatOps/DMOps_binding.cpp"

namespace py = pybind11;

PYBIND11_MODULE(LinSol, handle){

    handle.doc() = "This is the docs.";
    
    matrix_submodule_binding(handle);
    vector_submodule_binding(handle);
    dvops_submodule_binding(handle);
    dmops_submodule_binding(handle);
    
}