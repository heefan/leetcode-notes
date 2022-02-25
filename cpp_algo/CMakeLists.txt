cmake_minimum_required(VERSION 3.21)
project(cpp_algo)

set(CMAKE_CXX_STANDARD 20)

#include_directories("/usr/local/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(cpp_algo
        include/vector_helper.h
        include/binarytree_helper.h
        presum/presum.cpp
        dp/53_MaximumSubarray.cpp
        presum/560_subarray_sum_equals_k.cpp
        dfs/00/104.maxumum_depth_of_binary_tree.cpp
        graph/00.graph.cpp
        cpp_stl/stl_map.cpp quicksort/00_quicksort.cpp)
