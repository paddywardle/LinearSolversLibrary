set(MPIENV_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/MPIBasicEnv.cpp
)

target_sources(LinSol PRIVATE ${MPIENV_FILES})