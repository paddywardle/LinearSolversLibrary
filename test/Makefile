CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

MATRIX_FILES = $(shell find ../src/Matrix/ -name '*.cpp' -o -name '*.h')
MATOPS_FILES = $(shell find ../src/Ops/serial/ -name '*.cpp' -o -name '*.h')
VECTOR_FILES = $(shell find ../src/Vector/ -name '*.cpp' -o -name '*.h')
LINSOL_FILES = $(shell find ../src/LinearSolvers/serial -name '*.cpp' -o -name '*.h')
RESIDUALS_FILES = ../src/Residuals/Residuals.cpp
TEST_FILES = $(shell find . -name 'test_*.cpp')
OUT_FILE = ../bin/test_program

all: $(OUT_FILE)

$(OUT_FILE): main_test.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES) $(RESIDUALS_FILES) $(TEST_FILES) $(LINSOL_FILES) 
	$(CXX) -o $@ main_test.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES) $(LINSOL_FILES) $(RESIDUALS_FILES) $(TEST_FILES) $(TEST_FLAGS) -O3

clean:
	rm -f $(OUT_FILE)

.PHONY: all clean