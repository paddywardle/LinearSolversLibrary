set(TEST_EXAMPLE_FILES main_test.cpp)

find_package(GTest REQUIRED)

add_executable(test_program ${TEST_EXAMPLE_FILES})

target_link_libraries(test_program
                      GTest::GTest
                      LinSol)

enable_testing()