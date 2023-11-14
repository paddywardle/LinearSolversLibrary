#include "file_reader.h"

std::vector<std::vector<double>> read_matrix(std::string path){

        std::ifstream file(path);
        std::vector<std::vector<double>> A;
        std::string line;

        if (!file.is_open()){
            std::cerr<<"Error opening file.\n";
            return std::vector<std::vector<double>>(1, std::vector<double>(1, 0));
        }

        while (std::getline(file, line)){
            std::istringstream iss(line);
            std::vector<double> row;
            
            double value;

            while (iss >> value){
                row.push_back(value);

                if (iss.peek() == ','){
                    iss.ignore();
                }
            }

            A.push_back(row);
        }

        file.close();

        return A;
}

std::vector<double> read_vector(std::string path){

        std::ifstream file(path);
        std::vector<double> b;
        std::string line;

        if (!file.is_open()){
            std::cerr<<"Error opening file.\n";
            return std::vector<double>(1, 0);
        }

        while(std::getline(file, line)){

            std::istringstream iss(line);
                
            double value;

            while (iss >> value){
                b.push_back(value);
            }
        }

        file.close();

        return b;
}