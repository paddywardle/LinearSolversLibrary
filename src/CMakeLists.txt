add_library(LinSol)

find_package(OpenMP)

add_subdirectory(serial)

add_subdirectory(openmp)

add_subdirectory(Vector)

add_subdirectory(Matrix)

target_link_libraries(LinSol PUBLIC OpenMP::OpenMP_CXX)