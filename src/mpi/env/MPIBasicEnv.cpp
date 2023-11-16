#include "MPIBasicEnv.h"

void MPIBasicEnv::initialise(int argc, char* argv[]) const{
    MPI_Init(&argc, &argv);
}

void MPIBasicEnv::finalise() const{
    MPI_Finalize();
}