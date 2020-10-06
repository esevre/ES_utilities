//
// Created by esevre on 5/25/2020.
//

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

namespace ES::string {
    using namespace std;
    long hex2int(const std::string &hexStr)
    {
        char *offset;
        if (hexStr.length() > 2) {
            if (hexStr[0] == '0' && hexStr[1] == 'x') {
                return std::strtol(hexStr.c_str(), &offset, 0);
            }
            return std::strtol(hexStr.c_str(), &offset, 16);
        }
    }
}




