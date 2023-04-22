# This project shows how to use the CMake build system


# Minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Project name
project(RayTracerLib)

# Set the directory where binaries will be stored
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

# Set the directory where the executable will be stored
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# Set the output executable name, and the source files to be compiled
add_library(${PROJECT_NAME} STATIC
Camera.hpp Camera.cpp
constants.hpp
Driver.cpp Driver.hpp 
Light.cpp Light.hpp
matematical.cpp matematical.hpp
Material.cpp Material.hpp
Scene.cpp Scene.hpp
SDL_manager.cpp SDL_manager.hpp
Shape.cpp Shape.hpp 
Sphere.cpp Sphere.hpp
)

# Link the executable to the libraries we want to use (SO name of the library, without the "lib" prefix and the ".so" suffix)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2 SDL2main SDL2_image)

# Set the directory where the libraries are stored
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/SDL2_image-2.6.3/lib/x64/  ${CMAKE_SOURCE_DIR}/lib/SDL2-2.26.5/lib/x64)

# Set the directory where the header files are stored
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/SDL2_image-2.6.3/include/ ${CMAKE_SOURCE_DIR}/lib/SDL2-2.26.5/include/) 




