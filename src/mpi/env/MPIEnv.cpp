#include "MPIEnv.h"

MPIEnv::MPIEnv(int argc, char* argv[]){
    this->initialise(argc, argv);
}

MPIEnv::~MPIEnv(){
    this->finalise();
}