//
// Created by esevre on 4/29/2020.
//

#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace ES::file {
    void write(const std::string &filename, const std::string &contents);

    void write_binary(const std::string &filename, const char *data, const int size_in_char);

}


