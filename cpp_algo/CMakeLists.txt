cmake_minimum_required(VERSION 3.21)
project(cpp_algo)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_algo
        /usr/local/include
        vector_helper.h
        presum.cpp
)
