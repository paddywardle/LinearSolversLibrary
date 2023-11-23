#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Matrix/DenseMatrix_binding.h"
#include "Vector/DenseVector_binding.h"
#include "VecOps/DVOps_binding.h"
#include "MatOps/DMOps_binding.h"
#include "Residuals/Residuals_binding.h"
#include "LinearSolvers/LinearSolvers_binding.h"
#include "../src/Vector/DenseVector.h"
#include "../src/Matrix/DenseMatrix.h"

namespace py = pybind11;