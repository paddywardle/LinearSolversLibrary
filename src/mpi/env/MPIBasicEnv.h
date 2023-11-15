#ifndef MPIBASICENV_H
#define MPIBASICENV_H

#include "MPIEnv.h"

class MPIBasicEnv: public MPIEnv {

    public:

        MPIBasicEnv(int argc, char* argv[]) : MPIEnv(argc, argv){};

        void initialise(int argc, char* argv[]) const override;

        void finalise() const override;

        int rank() const override;

        int size() const override;

};

#endif