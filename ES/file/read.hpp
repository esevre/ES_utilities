//
// Created by esevre on 6/1/2020.
//

#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "filesize.hpp"

namespace ES::file {
    std::string read(const std::string &filename);
    std::vector<std::string> read_lines(const std::string &filename);

    void read_binary(const std::string &filename, std::string &data);
}
