#include "linSol.h"

PYBIND11_MODULE(LinSol, handle){

    handle.doc() = "This is the docs.";

    declareSubLinSol<DenseMatrix,DenseVector>(handle, "dense");
    
}