cmake_minimum_required(VERSION 3.21)
project(cpp_algo)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_algo
        /usr/local/include
        vector_helper.h
        presum/presum.cpp
        dp/53_MaximumSubarray.cpp presum/01_560_subarray_sum_equals_k.cpp)
