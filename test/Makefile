CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

SRC_FILES = ../src/Matrix.cpp
TEST_FILES = test_numRowsCols.cpp
OUT_FILE = ../bin/test_program

all: $(OUT_FILE)

$(OUT_FILE): main_test.cpp $(SRC_FILES) $(TEST_FILES)
	$(CXX) -o $@ main_test.cpp $(SRC_FILES) $(TEST_FILES) $(TEST_FLAGS)

clean:
	rm -f $(OUT_FILE)

.PHONY: all clean