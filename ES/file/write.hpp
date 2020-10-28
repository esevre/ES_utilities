//
// Created by esevre on 4/29/2020.
//

#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace ES::file {
    void write(
            const std::string &filename,
            const std::string &contents)
    {
        std::ofstream outfile(filename);
        outfile << contents;
    }

    template <class Container>
    void write_binary_container(
            const std::string &filename,
            const Container &container)
    {
        const long elt_size = sizeof(typename Container::value_type);
        std::ofstream outfile(filename, std::ios::binary);
        for (const auto &elt : container) {
            outfile.write((char*)&elt, elt_size);
        }
    }

    void write_binary(
            const std::string &filename,
            const char *data,
            const int size_in_char)
    {
        std::ofstream outfile(filename, std::ios::binary);
        outfile.write(data, size_in_char);
    }

}


