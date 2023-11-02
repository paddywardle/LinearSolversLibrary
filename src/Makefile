CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

MATRIX_FILES = $(shell find Matrix/ -name '*.cpp' -o -name '*.h')
MATOPS_FILES = $(shell find MatOps/ -name '*.cpp' -o -name '*.h')
VECTOR_FILES = $(shell find Vector/ -name '*.cpp' -o -name '*.h')
VECOPS_FILES = $(shell find VecOps/ -name '*.cpp' -o -name '*.h')
LINSOL_FILES = $(shell find LinearSolvers/ -name '*.cpp' -o -name '*.h')
RESIDUALS_FILES = $(shell find Residuals/ -name '*.cpp' -o -name '*.h')
OUT_FILE = ../bin/my_program

all: $(OUT_FILE)

$(OUT_FILE): main.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES) $(LINSOL_FILES) $(RESIDUALS_FILES)
	$(CXX) -g -o $@ main.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES) $(LINSOL_FILES) $(RESIDUALS_FILES)

clean:
	rm -f $(OUT_FILE)

.PHONY: all clean