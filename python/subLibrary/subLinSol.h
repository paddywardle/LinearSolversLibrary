#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../VecOps/vecOps.h"
#include "../MatOps/matOps.h"
#include "../Residuals/residuals.h"
#include "../LinearSolvers/linearSolvers.h"
#include "../Vector/vector.h"
#include "../Matrix/matrix.h"
#include "../../src/Vector/DenseVector.h"
#include "../../src/Matrix/DenseMatrix.h"

namespace py = pybind11;

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