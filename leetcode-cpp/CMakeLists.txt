cmake_minimum_required(VERSION 3.21)

project(leetcode_cpp LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

#Include(FetchContent)
#FetchContent_Declare(
#        Catch2
#        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#        GIT_TAG        v2.13.8
#)
#
#FetchContent_MakeAvailable(Catch2)

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/vendors/catch2/2.18.3/include")
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/vendors/catch2/2.18.3/include")
#find_package(Catch2 REQUIRED PATHS ${CMAKE_BUILD_RPATH}/cmake-build-debug/_deps/catch2-src/contrib/Catch.cmake)

include_directories("${PROJECT_SOURCE_DIR}/include")

set(HEADER
        ${PROJECT_SOURCE_DIR}/include/vector_helper.h
        ${PROJECT_SOURCE_DIR}/include/binarytree_helper.h
        ${PROJECT_SOURCE_DIR}/include/Catch.hpp
        )
set(TARGET leetcodeCpp)

set(SOURCE
        algorithms/quicksort/01_linklist_mergesort.cpp
        algorithms/graph/00.graph_bfs.cpp
        algorithms/quicksort/00_array_quicksort.cpp
        algorithms/kmp/kmp_algo.cpp
        algorithms/binary-search/binary-search-prototype.cpp
        skills/string_to_vector_ex.cpp
        skills/map_ex.cpp
        skills/int_string.cpp
        skills/vector_ex.cpp
        skills/odevity_ex.cpp
        skills/stl_set.cpp
        questions/presum/presum.cpp
        questions/dp/longest_subarray_problems/53_MaximumSubarray.cpp
        questions/presum/560.SubarraySumEqualsK.cpp
        questions/dfs/00/104.maxumum_depth_of_binary_tree.cpp
        questions/string/165.CompareVersionNumbers.cpp
        questions/2201.count_artifacts_that_can_be_extracted.cpp
        questions/binary_search/two_segment_problems/81.search-in-rotated-sorted-array-ii.cpp
        questions/binary_search/prototype-problems/33.search-in-rotated-sorted-array.cpp
        questions/binary_search/74.search-a-2d-matrix.cpp
        algorithms/binary-search/binary-search-02.cpp questions/binary_search/left-right-range-problems/287.find-the-duplicate-number.cpp questions/palindrome/680.valid-palindrome-ii.cpp questions/dp/longest_subsequence_problems/673.number_of_longest_increasing_subsequence.cpp include/common_inc.h questions/dp/longest_subsequence_problems/300.longest_increasing_subsequence.cpp questions/LRU/prototype/146.LRU_Cache.cpp questions/graph/1042.flower_plating_with_no_adjacent.cpp)

add_executable(${TARGET} ${SOURCE} ${HEADER})
