CXX = g++
TEST_FLAGS = -lgtest -lgtest_main -pthread

SRC_DIR = ../src
TEST_DIR = .

SRC_FILES = $(wilcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

SRC_OBJ = $(SRC_FILES:.cpp=.o)
TEST_OBJ = $(TEST_FILES:.cpp=.o)

TEST_EXECUTABLE = test_program

all: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(SRC_OBJ) $(TEST_OBJ)
	$(CXX) -o $@ $(SRC_OBJ) $(TEST_OBJ) $(TEST_FLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c -o $@ $<

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) -c -o $@ $<

clean:
	rm -f $(SRC_OBJ) $(TEST_OBJ)

.PHONY: all clean