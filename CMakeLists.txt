cmake_minimum_required(VERSION 3.5.0)

project(crc-table)

set(CMAKE_CXX_STANDARD 17)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(crc-table main.cpp Crc8.cpp Crc16.cpp Crc32.cpp Crc64.cpp)
