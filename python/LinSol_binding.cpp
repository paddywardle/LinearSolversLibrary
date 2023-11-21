#include "LinSol_binding.h"

PYBIND11_MODULE(LinSol, handle){

    handle.doc() = "This is the docs.";
    
    matrix_submodule_binding(handle);
    vector_submodule_binding(handle);
    dvops_submodule_binding<DenseMatrix,DenseVector>(handle, "Dense");
    dmops_submodule_binding<DenseMatrix>(handle, "Dense");
    res_submodule_binding<DenseMatrix,DenseVector>(handle, "Dense");
    solvers_submodule_binding<DenseMatrix,DenseVector>(handle, "Dense");
    
}