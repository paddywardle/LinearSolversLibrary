#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "../../../src/utils/file_reader.h"

#include "../../../src/Matrix/DenseMatrix.h"
#include "../../../src/serial/MatOps/DMOps.h"
#include "../../../src/Vector/Vector.h"
#include "../../../src/serial/VecOps/DVOps.h"
#include "../../../src/serial/LinearSolvers/GaussSeidel.h"
#include "../../../src/Exceptions/DenseMatrixExceptions.h"
#include "../../../src/Exceptions/DenseVectorExceptions.h"
#include "../../../src/serial/LinearSolvers/SteepestDescent.h"
#include "../../../src/serial/LinearSolvers/ConjugateGradient.h"
#include "../../../src/openmp/LinearSolversOMP/GaussSeidelOMP.h"
#include "../../../src/openmp/LinearSolversOMP/JacobiOMP.h"
#include "../../../src/openmp/LinearSolversOMP/GaussianEliminationOMP.h"