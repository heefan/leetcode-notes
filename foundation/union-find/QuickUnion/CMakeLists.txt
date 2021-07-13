cmake_minimum_required(VERSION 3.19)
project(QuickUnion)

set(CMAKE_CXX_STANDARD 14)
include($ENV{ALGO_WORKSPACE}/build/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(QuickUnion main.cpp ${CONAN_LIBS})