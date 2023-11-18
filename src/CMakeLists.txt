add_library(LinSol)

find_package(OpenMP REQUIRED)

find_package(MPI REQUIRED)

add_subdirectory(LinearSolvers)

# add_subdirectory(openmp)

add_subdirectory(mpi)

add_subdirectory(Vector)

add_subdirectory(Matrix)

add_subdirectory(utils)

target_link_libraries(LinSol PUBLIC OpenMP::OpenMP_CXX)