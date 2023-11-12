set (SERIAL_SOLVER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/GaussSeidel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Jacobi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SteepestDescent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConjugateGradient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/GaussianElimination.cpp)

target_sources(LinSol PRIVATE ${SERIAL_SOLVER_FILES})