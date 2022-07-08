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
        doc/quicksort/01_linklist_mergesort.cpp
        doc/graph/00.graph_bfs.cpp
        doc/quicksort/00_array_quicksort.cpp
        doc/kmp/kmp_algo.cpp
        doc/binary-search/binary-search.cpp
        skills/string_to_vector_ex.cpp
        skills/map_ex.cpp
        skills/int_string.cpp
        skills/vector_ex.cpp
        skills/odevity_ex.cpp
        skills/stl_set.cpp
        leetcode/00.foundation/presum/presum.cpp
        leetcode/00.foundation/dp/longest_subarray_problems/53_MaximumSubarray.cpp
        leetcode/00.foundation/presum/560.SubarraySumEqualsK.cpp
        leetcode/104.maxumum_depth_of_binary_tree.cpp
        leetcode/00.foundation/string/165.CompareVersionNumbers.cpp
        leetcode/2201.count_artifacts_that_can_be_extracted.cpp
        leetcode/00.foundation/binary_search/search-in-roteated-array/81.search-in-rotated-sorted-array-ii.cpp
        leetcode/00.foundation/binary_search/search-in-roteated-array/33.search-in-rotated-sorted-array.cpp
        leetcode/00.foundation/binary_search/search-in-2d-array/74.search-a-2d-matrix.cpp
        leetcode/00.foundation/binary_search/find-duplicates-problems/287.find-the-duplicate-number.cpp leetcode/00.foundation/palindrome/680.valid-palindrome-ii.cpp leetcode/00.foundation/dp/longest_subsequence_problems/673.number_of_longest_increasing_subsequence.cpp include/common_inc.h leetcode/00.foundation/dp/longest_subsequence_problems/300.longest_increasing_subsequence.cpp leetcode/00.foundation/LRU/prototype/146.LRU_Cache.cpp leetcode/00.foundation/graph/1042.flower_plating_with_no_adjacent.cpp leetcode/128.longest_consecutive_sequence.cpp leetcode/00.foundation/backtracking/subset-combination-problems/90.subsets_II_sln2.cpp leetcode/00.foundation/backtracking/subset-combination-problems/78.subsets_sln1.cpp leetcode/00.foundation/backtracking/subset-combination-problems/78.subsets_sln2.cpp leetcode/00.foundation/backtracking/subset-combination-problems/90.subsets_II_sln1.cpp leetcode/00.foundation/backtracking/permutation-problems/46.Permutations.cpp leetcode/00.foundation/backtracking/permutation-problems/47.Permutations_II.cpp leetcode/00.foundation/backtracking/combination-problems/77.Combinations.cpp leetcode/00.foundation/backtracking/permutation-problems/prototype/permutation-test.cpp "leetcode/00.foundation/backtracking/combination-problems/39.combination-sum.cpp" leetcode/00.foundation/backtracking/22.generate-parentheses.cpp leetcode/00.foundation/union_find/prototype/union-find.cpp leetcode/01.practice/array/217.contains-duplicate.cpp leetcode/01.practice/array/219.contains-duplicate-II.cpp leetcode/01.practice/array/in-place-swap/448.find-all-numbers-disappeared-in-an-array.cpp leetcode/01.practice/bit-manipulation/136.single-number.cpp leetcode/01.practice/2d-array/2022.convert-1D-array-into-2D-array.cpp leetcode/00.foundation/prefix-suffix-product/prefix-product-prototype.cpp leetcode/00.foundation/prefix-suffix-product/suffix-product-prototype.cpp leetcode/00.foundation/prefix-suffix-product/238.product-of-array-expect-self.cpp leetcode/01.practice/array/find-duplicate-problems/287-in-place-swap-solution.cpp leetcode/01.practice/array/find-duplicate-problems/287-binary-search-solution.cpp leetcode/01.practice/array/find-duplicate-problems/287-floyd-cycle-detection-solution.cpp leetcode/00.foundation/binary_search/blue-red-problems/704.binary-search.cpp doc/binary-search/binary-search-blue-red-solution.cpp leetcode/00.foundation/binary_search/blue-red-problems/744.find-smallest-letter-greater-than-target.cpp leetcode/00.foundation/binary_search/search-in-moutain/852.peak-index-in-a-moutain-array.cpp leetcode/00.foundation/binary_search/search-in-roteated-array/153.find-minimum-in-rotated-sorted-array.cpp leetcode/00.foundation/heap/215.find-kth-largest-element-in-an-array.cpp leetcode/00.foundation/heap/378.kth-smallest-element-in-a-sorted-matrix.cpp leetcode/00.foundation/heap/373.find-k-pairs-with-smallest-sums.cpp include/pq_helper.h leetcode/00.foundation/heap/703.kth-largetst-element-in-a-stream.cpp doc/trie/trie.cpp leetcode/00.foundation/tire/208.implement-trie.cpp)

add_executable(${TARGET} ${SOURCE} ${HEADER})
