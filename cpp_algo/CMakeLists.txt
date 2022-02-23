cmake_minimum_required(VERSION 3.21)
project(cpp_algo)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_algo
        /usr/local/include
        vector_helper.h
        presum/presum.cpp
        dp/53_MaximumSubarray.cpp
        presum/560_subarray_sum_equals_k.cpp
        dfs/00/104.maxumum_depth_of_binary_tree.cpp
        binarytree_helper.h
        graph/00.graph.cpp
        cpp_stl/stl_map.cpp)
