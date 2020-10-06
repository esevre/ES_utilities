//
// Created by esevre on 6/1/2020.
//

#include "filesize.hpp"

namespace ES::file{
    size_t filesize(const std::string &filename)
    {
        std::ifstream infile(filename);
        infile.seekg(0, std::ios::end);
        return infile.tellg();
    }
}


