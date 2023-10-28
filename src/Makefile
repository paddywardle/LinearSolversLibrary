CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

MATRIX_FILES = $(shell find Matrix/ -name '*.cpp')
MATOPS_FILES = $(shell find MatOps/ -name '*.cpp')
VECTOR_FILES = $(shell find Vector/ -name '*.cpp')
VECOPS_FILES = $(shell find VecOps/ -name '*.cpp')
OUT_FILE = ../bin/my_program

all: $(OUT_FILE)

$(OUT_FILE): main.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES)
	$(CXX) -o $@ main.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(VECTOR_FILES) $(VECOPS_FILES)

clean:
	rm -f $(OUT_FILE)

.PHONY: all clean