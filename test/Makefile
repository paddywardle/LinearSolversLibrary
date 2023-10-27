CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

MATRIX_FILES = $(shell find ../src/Matrix/ -name '*.cpp')
MATOPS_FILES = $(shell find ../src/MatOps/ -name '*.cpp')
TEST_FILES = $(shell find . -name "test_*.cpp")
OUT_FILE = ../bin/test_program

all: $(OUT_FILE)

$(OUT_FILE): main_test.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(TEST_FILES)
	$(CXX) -o $@ main_test.cpp $(MATRIX_FILES) $(MATOPS_FILES) $(TEST_FILES) $(TEST_FLAGS)

clean:
	rm -f $(OUT_FILE)

.PHONY: all clean