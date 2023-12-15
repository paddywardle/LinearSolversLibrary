#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "../../../src/utils/file_reader.h"

#include "../../../src/mpi/env/MPIBasicEnv.h"

#include "../../../src/Exceptions/DenseMatrixExceptions.h"
#include "../../../src/Exceptions/DenseVectorExceptions.h"

#include "../../../src/Matrix/DenseMatrix.h"
#include "../../../src/Matrix/Sparse/SparseMatrix.h"
#include "../../../src/Vector/Sparse/SparseVector.h"
#include "../../../src/Vector/Vector.h"

#include "../../../src/Ops/serial/VecOps.h"
#include "../../../src/Ops/serial/MatOps.h"

#include "../../../src/LinearSolvers/serial/GaussSeidel.h"
#include "../../../src/LinearSolvers/serial/Jacobi.h"
#include "../../../src/LinearSolvers/serial/SteepestDescent.h"
#include "../../../src/LinearSolvers/serial/ConjugateGradient.h"

#include "../../../src/LinearSolvers/omp/GaussSeidelOMP.h"
#include "../../../src/LinearSolvers/omp/JacobiOMP.h"
#include "../../../src/LinearSolvers/omp/SteepestDescentOMP.h"
#include "../../../src/LinearSolvers/omp/ConjugateGradientOMP.h"