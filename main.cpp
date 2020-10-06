
#include <iostream>

#include "ES/file/read.hpp"

int main() {
    std::string filename = "../main.cpp";
    auto contents = ES::file::read(filename);

    auto lines = ES::file::read_lines(filename);

    std::cout << "Hello, World!" << std::endl;
//    std::cout << contents << std::endl;
    for (const auto &line : lines) {
        std::cout << line << '\n';
    }
    return 0;
}

