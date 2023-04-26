# This project shows how to use the CMake build system


# Minimum required version of CMake
cmake_minimum_required(VERSION 3.16..3.24)

project(RayTracer
    VERSION 0.1
    DESCRIPTION "Ray Tracer using C++, CMake and the SDL library" 
    LANGUAGES CXX
)

include(CTest)

add_subdirectory(./src)

add_subdirectory(./external)

add_subdirectory(./tests)

