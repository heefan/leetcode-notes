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

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/vendors/catch2/2.18.3/include")
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/vendors/catch2/2.18.3/include")
#find_package(Catch2)
find_package(Catch2 REQUIRED)
#find_package(Catch2 REQUIRED PATHS ${CMAKE_BUILD_RPATH}/cmake-build-debug/_deps/catch2-src/contrib/Catch.cmake)

add_executable(leetcode_cpp
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

target_link_libraries(leetcode_cpp Catch2::Catch2)
include(CTest)
include(Catch)
catch_discover_tests(leetcode_cpp)

