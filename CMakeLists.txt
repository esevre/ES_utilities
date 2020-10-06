cmake_minimum_required(VERSION 3.16)
project(ES_utilities)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Google_test)

add_executable(ES_utilities main.cpp ES/file/write.cpp ES/file/write.hpp ES/string/string2numeric.hpp ES/file/read.cpp ES/file/read.hpp ES/file/filesize.cpp ES/file/filesize.hpp)



