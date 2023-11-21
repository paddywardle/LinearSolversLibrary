cmake_minimum_required(VERSION 3.4)
project(pybindTest)
add_subdirectory(pybind11)

set (DenseVectorSrc "../src/Vector/DenseVector.cpp")

set (DenseMatrixSrc "../src/Matrix/DenseMatrix.cpp")

set (DVOpsSrc "../src/Ops/serial/DVOps.cpp")

set (DMOpsSrc "../src/Ops/serial/DMOps.cpp")

set (ResidualsSrc "../src/Residuals/Residuals.cpp")

set (LinearSolversSrc 
    "../src/LinearSolvers/serial/GaussSeidel.cpp"
    "../src/LinearSolvers/serial/Jacobi.cpp"
    "../src/LinearSolvers/serial/SteepestDescent.cpp"
    "../src/LinearSolvers/serial/ConjugateGradient.cpp"
    "../src/LinearSolvers/serial/GaussianElimination.cpp")

set (LinSol "LinSol_binding.cpp")

pybind11_add_module(LinSol ${LinSol} ${DenseVectorSrc} ${DenseMatrixSrc} ${DVOpsSrc} ${DMOpsSrc} ${ResidualsSrc} ${LinearSolversSrc})