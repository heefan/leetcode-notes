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
find_package(Catch2 REQUIRED)

set(HEADER
        ${PROJECT_SOURCE_DIR}/include/vector_helper.h
        ${PROJECT_SOURCE_DIR}/include/binarytree_helper.h
        )
set(TARGET leetcodeCpp)

set(SOURCE
        ${PROJECT_SOURCE_DIR}/algorithms/quicksort/01_linklist_mergesort.cpp
        ${PROJECT_SOURCE_DIR}/algorithms/graph/00.graph_bfs.cpp
        ${PROJECT_SOURCE_DIR}/algorithms/quicksort/00_array_quicksort.cpp
        ${PROJECT_SOURCE_DIR}/algorithms/kmp/kmp_algo.cpp
        ${PROJECT_SOURCE_DIR}/algorithms/binary-search/binary_search_prototype.cpp
        ${PROJECT_SOURCE_DIR}/skills/string_to_vector_ex.cpp
        ${PROJECT_SOURCE_DIR}/skills/map_ex.cpp
        ${PROJECT_SOURCE_DIR}/skills/int_string.cpp
        ${PROJECT_SOURCE_DIR}/skills/vector_ex.cpp
        ${PROJECT_SOURCE_DIR}/skills/odevity_ex.cpp
        ${PROJECT_SOURCE_DIR}/skills/stl_set.cpp
        ${PROJECT_SOURCE_DIR}/questions/presum/presum.cpp
        ${PROJECT_SOURCE_DIR}/questions/dp/53_MaximumSubarray.cpp
        ${PROJECT_SOURCE_DIR}/questions/presum/560.SubarraySumEqualsK.cpp
        ${PROJECT_SOURCE_DIR}/questions/dfs/00/104.maxumum_depth_of_binary_tree.cpp
        ${PROJECT_SOURCE_DIR}/questions/string/165.CompareVersionNumbers.cpp
        ${PROJECT_SOURCE_DIR}/questions/2201.count_artifacts_that_can_be_extracted.cpp
        ${PROJECT_SOURCE_DIR}/questions/binary_search/81.search-in-rotated-sorted-array-ii.cpp
        ${PROJECT_SOURCE_DIR}/questions/binary_search/33.search_in_rotated_sorted_array.cpp
        )

add_executable(${TARGET} ${SOURCE} ${HEADER})

target_link_libraries(${TARGET} Catch2::Catch2)
include(CTest)
include(Catch)
catch_discover_tests(${TARGET})
