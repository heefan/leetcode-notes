cmake_minimum_required(VERSION 3.21)
project(cpp_algo)

set(CMAKE_CXX_STANDARD 20)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(cpp_algo
        include/vector_helper.h
        include/binarytree_helper.h
        # foundation dir
        foundation/quicksort/01_linklist_mergesort.cpp
        foundation/graph/00.graph_bfs.cpp
        foundation/quicksort/00_array_quicksort.cpp
        foundation/kmp/kmp_algo.cpp
        # cpp_stl dir
        cpp_stl/string_to_vector_ex.cpp
        cpp_stl/map_ex.cpp
        cpp_stl/int_string.cpp
        # leetcode dir
        leetcode/presum/presum.cpp
        leetcode/dp/53_MaximumSubarray.cpp
        leetcode/presum/560.SubarraySumEqualsK.cpp
        leetcode/dfs/00/104.maxumum_depth_of_binary_tree.cpp
        leetcode/string/165.CompareVersionNumbers.cpp cpp_stl/vector_ex.cpp
        leetcode/2201.CountArtifactsThatCanBeExtracted.cpp)
