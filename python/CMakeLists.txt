cmake_minimum_required(VERSION 3.4)
project(pybindTest)

add_subdirectory(pybind11)

set (ResidualsSrc "../src/Residuals/Residuals.cpp")

set (MatOpsSrc "../src/Ops/serial/MatOps.cpp")

set (VecOpsSrc "../src/Ops/serial/VecOps.cpp")

set (DenseVectorSrc "../src/Vector/DenseVector.cpp")

set (DenseMatrixSrc "../src/Matrix/DenseMatrix.cpp")

set (LinearSolversSrc 
    "../src/LinearSolvers/serial/GaussSeidel.cpp"
    "../src/LinearSolvers/serial/Jacobi.cpp"
    "../src/LinearSolvers/serial/SteepestDescent.cpp"
    "../src/LinearSolvers/serial/ConjugateGradient.cpp"
    "../src/LinearSolvers/serial/GaussianElimination.cpp")

set (LinSol "linSol.cpp")

pybind11_add_module(LinSol 
                    ${LinSol}
                    ${DenseVectorSrc} 
                    ${DenseMatrixSrc} 
                    ${MatOpsSrc} 
                    ${VecOpsSrc} 
                    ${ResidualsSrc} 
                    ${LinearSolversSrc}
)