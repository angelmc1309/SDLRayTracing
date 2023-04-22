# This project shows how to use the CMake build system


# Minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(RayTracer)

add_subdirectory(./src)

add_subdirectory(./src/launcher)

#add_subdirectory(./tests)