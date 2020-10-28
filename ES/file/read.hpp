//
// Created by esevre on 6/1/2020.
//

#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "filesize.hpp"

namespace ES::file {
    std::string read(const std::string &filename)
    {
        std::string contents;
        contents.reserve(filesize(filename));

        std::ifstream infile(filename);
        contents.assign((std::istreambuf_iterator<char>(infile)),
                        std::istreambuf_iterator<char>());
        return contents;
    }

    std::vector<std::string> read_lines(const std::string &filename)
    {
        std::vector<std::string> lines;
        std::ifstream infile(filename);
        std::string line;
        line.reserve(filesize(filename));
        std::getline(infile, line);
        while (!infile.eof()){
            lines.push_back(line);
            std::getline(infile, line);
        }
        return lines;
    }

    template <class Container>
    void read_binary_container(const std::string &filename, Container &container)
    {
        auto sz = filesize(filename);
        std::size_t value_sz = sizeof(typename Container::value_type);

        container.resize(sz/value_sz);

        std::ifstream infile(filename, std::ios::binary);
        typename Container::value_type value;
        for (int i = 0; i < container.size(); ++i) {
            infile.read((char*) &value, value_sz);
            container[i] = value;
        }
    }

}


