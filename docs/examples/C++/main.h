#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "../../../src/utils/file_reader.h"

#include "../../../src/mpi/env/MPIBasicEnv.h"

#include "../../../src/Exceptions/DenseMatrixExceptions.h"
#include "../../../src/Exceptions/DenseVectorExceptions.h"

#include "../../../src/Matrix/DenseMatrix.h"
#include "../../../src/Vector/Vector.h"

#include "../../../src/serial/VecOps/DVOps.h"
#include "../../../src/serial/MatOps/DMOps.h"
#include "../../../src/LinearSolvers/serial/GaussSeidel.h"
#include "../../../src/LinearSolvers/serial/Jacobi.h"
#include "../../../src/LinearSolvers/serial/SteepestDescent.h"
#include "../../../src/LinearSolvers/serial/ConjugateGradient.h"

#include "../../../src/openmp/LinearSolversOMP/GaussSeidelOMP.h"
#include "../../../src/openmp/LinearSolversOMP/JacobiOMP.h"
#include "../../../src/openmp/LinearSolversOMP/GaussianEliminationOMP.h"
#include "../../../src/openmp/LinearSolversOMP/ConjugateGradientOMP.h"