#include "MPIOps.h"

int MPIOps::rank() {

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    return rank;
}

int MPIOps::size() {

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    return size;
}