cmake_minimum_required(VERSION 3.4)
project(pybindTest)
add_subdirectory(pybind11)

set (DenseVectorSrc "../src/Vector/DenseVector.cpp")

set (DenseMatrixSrc "../src/Matrix/DenseMatrix.cpp")

set (DVOpsSrc "../src/serial/VecOps/DVOps.cpp")

set (DMOpsSrc "../src/serial/MatOps/DMOps.cpp")

set (ResidualsSrc "../src/serial/Residuals/Residuals.cpp")

set (LinearSolversSrc 
    "../src/serial/LinearSolvers/GaussSeidel.cpp"
    "../src/serial/LinearSolvers/Jacobi.cpp"
    "../src/serial/LinearSolvers/SteepestDescent.cpp"
    "../src/serial/LinearSolvers/ConjugateGradient.cpp"
    "../src/serial/LinearSolvers/GaussianElimination.cpp")

set (LinSol "LinSol_binding.cpp")

pybind11_add_module(LinSol ${LinSol} ${DenseVectorSrc} ${DenseMatrixSrc} ${DVOpsSrc} ${DMOpsSrc} ${ResidualsSrc} ${LinearSolversSrc})