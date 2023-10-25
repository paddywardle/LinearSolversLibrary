CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

SRC_FILES = $(shell find Matrix/ -name '*.cpp')
OUT_FILE = ../bin/my_program

all: $(OUT_FILE)

$(OUT_FILE): main.cpp $(SRC_FILES) $(TEST_FILES)
	$(CXX) -o $@ main.cpp $(SRC_FILES)

clean:
	rm -f $(OUT_FILE)

.PHONY: all clean