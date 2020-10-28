//
// Created by esevre on 4/29/2020.
//
//  Google test C++ file for ES/file/write.hpp

//
// Do to file creation, I am not sure how to test this yet...

#include <gtest/gtest.h>
#include <array>
#include <vector>

#include "../../../ES/file/read.hpp"
#include "../../../ES/file/write.hpp"


class ReadWriteSuite : public ::testing::Test {
protected:
    std::string path = "../../Google_test/ES/file/";

    std::vector<double> vec_d1 { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    std::array<double, 5> arr_d1 {1.1, 2.2, 3.3, 4.4, 5.5};
};

TEST_F(ReadWriteSuite, empty_input)
{
    // todo: replace with real test later
    int x = 1;
    EXPECT_EQ(x, 1);

}

TEST_F(ReadWriteSuite, correct_write_size)
{
//    std::string path = "../../Google_test/ES/file/";
    std::string filename = path + "GOOGLE_testfile.txt";
    std::string str = "abcde";
    ES::file::write(filename, str);
    auto sz = ES::file::filesize(filename);
    EXPECT_EQ(sz, str.size());
    std::string str2 = "asdlkfjaslfdkjasfldsajflsajfldsajfldsajflksdajfldsajflsad";
    ES::file::write(filename, str2);
    sz = ES::file::filesize(filename);
    EXPECT_EQ(sz, str2.size());

    str = "a";
    ES::file::write(filename, str);
    sz = ES::file::filesize(filename);
    EXPECT_EQ(sz, str.size()) << "wrong size for single character in file";

}

TEST_F(ReadWriteSuite, vector_files)
{
    std::string filename_d = path + "Gtest_doubles.dat";
    ES::file::write_binary_container(filename_d, vec_d1);
    auto sz = ES::file::filesize(filename_d);
    EXPECT_EQ(sz, sizeof(double)*vec_d1.size()) << "double vector wrong size";

    ES::file::write_binary_container(filename_d, arr_d1);
    sz = ES::file::filesize(filename_d);
    EXPECT_EQ(sz, sizeof(double)*arr_d1.size()) << "double array wrong size";

}

TEST_F(ReadWriteSuite, binary_large_vector)
{
    const std::size_t size = 100'000;
    std::vector<double> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = i * 1.1;
    }
    std::string filename_d = path + "Gtest_doubles.dat";
    ES::file::write_binary_container(filename_d, vec);
    std::vector<double> vec_target;
    ES::file::read_binary_container(filename_d, vec_target);
    ASSERT_EQ(vec.size(), vec_target.size()) << "vector size is different after reading";

    for (int i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], vec_target[i]) << "source and target vector differe at index: " << i;
    }
    // if tests pass, then reset the file to a small one
    vec.resize(1);
    ES::file::write_binary_container(filename_d, vec);

}



