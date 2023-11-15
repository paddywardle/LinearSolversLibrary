#include "MPIBasicEnv.h"

void MPIBasicEnv::initialise(int argc, char* argv[]) const{
    MPI_Init(&argc, &argv);
}

void MPIBasicEnv::finalise() const{
    MPI_Finalize();
}

int MPIBasicEnv::rank() const{

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    return rank;
}

int MPIBasicEnv::size() const{

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    return size;
}