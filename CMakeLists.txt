cmake_minimum_required(VERSION 3.16)
project(FinalProject)

set(CMAKE_CXX_STANDARD 20)

include_directories(libs)

set(SOURCE_FILES libs/lib.cpp)

add_executable(FinalProject main.cpp libs/lib.cpp libs/lib.h)