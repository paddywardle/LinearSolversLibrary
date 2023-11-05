cmake_minimum_required(VERSION 3.4)
project(pybindTest)
add_subdirectory(pybind11)

set (DenseVectorSrc "../src/Vector/DenseVector.cpp")

set (DenseMatrixSrc "../src/Matrix/DenseMatrix.cpp")

set (DVOpsSrc "../src/VecOps/DVOps.cpp")

set (DMOpsSrc "../src/MatOps/DMOps.cpp")

set (ResidualsSrc "../src/Residuals/Residuals.cpp")

set (LinearSolversSrc 
    "../src/LinearSolvers/GaussSeidel.cpp"
    "../src/LinearSolvers/Jacobi.cpp"
    "../src/LinearSolvers/SteepestDescent.cpp"
    "../src/LinearSolvers/ConjugateGradient.cpp")

set (LinSol "LinSol_binding.cpp")

pybind11_add_module(LinSol ${LinSol} ${DenseVectorSrc} ${DenseMatrixSrc} ${DVOpsSrc} ${DMOpsSrc} ${ResidualsSrc} ${LinearSolversSrc})