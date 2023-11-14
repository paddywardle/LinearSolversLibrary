set (OMP_SOLVER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/GaussSeidelOMP.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/JacobiOMP.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/GaussianEliminationOMP.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ConjugateGradientOMP.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SteepestDescentOMP.cpp
    )

target_sources(LinSol PRIVATE ${OMP_SOLVER_FILES})