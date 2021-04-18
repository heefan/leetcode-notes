cmake_minimum_required(VERSION 3.18)

project(main)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "./*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
add_custom_target(run
    COMMAND ${CMAKE_PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
