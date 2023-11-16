#ifndef MPIENV_H
#define MPIENV_H

#include <mpi.h>

// abstract base class for mpi environment initialisation
class MPIEnv{

    public:

        MPIEnv(int argc, char* argv[]);

        ~MPIEnv();

        virtual void initialise(int argc, char* argv[]) const=0;
        
        virtual void finalise() const=0;

};

#endif