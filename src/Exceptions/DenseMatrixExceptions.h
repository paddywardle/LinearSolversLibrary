#ifndef DENSEMATRIXEXCEPTIONS_H
#define DENSEMATRIXEXCEPTIONS_H

#include <stdexcept>
#include <string>

class DenseMatrixExceptions : public std::runtime_error {

    public:
        DenseMatrixExceptions(const std::string& message) : std::runtime_error(message){};

};

#endif
