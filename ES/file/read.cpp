//
// Created by esevre on 6/1/2020.
//

#include "read.hpp"

namespace ES::file{
    std::string read(const std::string &filename) {
        std::string contents;
        contents.reserve(filesize(filename));

        std::ifstream infile(filename);
        contents.assign((std::istreambuf_iterator<char>(infile)),
                        std::istreambuf_iterator<char>());
        return contents;
    }

    std::vector<std::string> read_lines(const std::string &filename) {
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

    // this needs to be done in a more templated way.
    void read_binary(const std::string &filename, std::string &data) {
        auto file_size = filesize(filename);
        data.resize(file_size);
        std::ifstream infile(filename, std::ios::binary);
        infile.read(data.data(), file_size);
    }
}

