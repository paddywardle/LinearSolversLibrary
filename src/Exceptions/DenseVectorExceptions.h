#ifndef DENSEVECTOREXCEPTIONS_H
#define DENSEVECTOREXCEPTIONS_H

#include <stdexcept>
#include <string>

class DenseVectorExceptions : public std::runtime_error {

    public:
        DenseVectorExceptions(const std::string& message) : std::runtime_error(message){};

};

#endif
