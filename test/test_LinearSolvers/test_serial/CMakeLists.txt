set (TEST_SERIAL_SOLVER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_GaussSeidel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_Jacobi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_SteepestDescent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_ConjugateGradient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_GaussianElimination.cpp
    )

target_link_libraries(LinSol PRIVATE ${TEST_SERIAL_SOLVER_FILES})