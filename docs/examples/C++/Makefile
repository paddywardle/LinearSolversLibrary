CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

MATRIX_FILES = $(shell find ../../../src/Matrix/ -name '*.cpp' -o -name '*.h')
MATOPS_FILES = $(shell find ../../../src/MatOps/ -name '*.cpp' -o -name '*.h')
VECTOR_FILES = $(shell find ../../../src/Vector/ -name '*.cpp' -o -name '*.h')
VECOPS_FILES = $(shell find ../../../src/VecOps/ -name '*.cpp' -o -name '*.h')
LINSOL_FILES = $(shell find ../../../src/LinearSolvers/ -name '*.cpp' -o -name '*.h')
RESIDUALS_FILES = $(shell find ../../../src/Residuals/ -name '*.cpp' -o -name '*.h')
OUT_FILE = ../../../bin/my_program

all: $(OUT_FILE)

$(OUT_FILE): main.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES) $(LINSOL_FILES) $(RESIDUALS_FILES)
	$(CXX) -o $@ main.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES) $(LINSOL_FILES) $(RESIDUALS_FILES)

clean:
	rm -f $(OUT_FILE)

.PHONY: all clean