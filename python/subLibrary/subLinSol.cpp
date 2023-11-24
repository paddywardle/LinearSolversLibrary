#include "subLinSol.h"

template<typename Matrix, typename Vector>
void declareSubLinSol(py::module handle, std::string libName){

    handle.doc() = "This is the docs.";

    auto lib = handle.def_submodule(libName.c_str());
    
    declareMatrix<Matrix>(lib);
    declareVector<Vector>(lib);
    declareVecOps<Matrix,Vector>(lib);
    declareMatOps<Matrix>(lib);
    declareResiduals<Matrix,Vector>(lib);
    declareLinearSolvers<Matrix,Vector>(lib);
    
}