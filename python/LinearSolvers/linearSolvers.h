#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>

#include "../../src/LinearSolvers/serial/GaussSeidel.h"
#include "../../src/LinearSolvers/serial/Jacobi.h"
#include "../../src/LinearSolvers/serial/SteepestDescent.h"
#include "../../src/LinearSolvers/serial/ConjugateGradient.h"
#include "../../src/LinearSolvers/serial/GaussianElimination.h"

#include "directSolvers.h"
#include "iterativeSolvers.h"

namespace py = pybind11;