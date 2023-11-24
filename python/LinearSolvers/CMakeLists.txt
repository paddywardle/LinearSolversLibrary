set (LinearSolversSrc 
    "../src/LinearSolvers/serial/GaussSeidel.cpp"
    "../src/LinearSolvers/serial/Jacobi.cpp"
    "../src/LinearSolvers/serial/SteepestDescent.cpp"
    "../src/LinearSolvers/serial/ConjugateGradient.cpp"
    "../src/LinearSolvers/serial/GaussianElimination.cpp" PARENT_SCOPE)

set (LinearSolversBindings "LinearSolvers/linearSolvers.cpp" 
                           "LinearSolvers/iterativeSolvers.cpp" 
                           "LinearSolvers/directSolvers.cpp" 
                           PARENT_SCOPE)