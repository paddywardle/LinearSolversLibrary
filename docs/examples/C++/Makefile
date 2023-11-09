CXX = g++
FLAGS = -fopenmp -O3

SRC_DIR = ../../../src
OUT_FILE = ../../../bin/my_program

MATRIX_DIR = $(SRC_DIR)/Matrix
MATOPS_DIR = $(SRC_DIR)/MatOps
VECTOR_DIR = $(SRC_DIR)/Vector
VECOPS_DIR = $(SRC_DIR)/VecOps
LINSOL_DIR = $(SRC_DIR)/LinearSolvers
LINSOLOMP_DIR = $(SRC_DIR)/LinearSolversOMP
RESIDUALS_DIR = $(SRC_DIR)/Residuals

SRC_DIRS = $(MATRIX_DIR) $(MATOPS_DIR) $(VECTOR_DIR) $(VECOPS_DIR) $(LINSOL_DIR) $(LINSOLOMP_DIR) $(RESIDUALS_DIR)
SRC_FILES = $(shell find $(SRC_DIRS) -name '*.cpp')

all: $(OUT_FILE)

$(OUT_FILE): main.cpp $(SRC_FILES)
	$(CXX) -o $@ $^ $(FLAGS)