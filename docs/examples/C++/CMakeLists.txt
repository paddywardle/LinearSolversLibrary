set(CPP_EXAMPLE_FILES main.cpp)

add_executable(CppExample ${CPP_EXAMPLE_FILES})

target_link_libraries(CppExample PRIVATE LinSol)