add_executable(RayTracer main.cpp)

# Set the directory where the executable will be stored
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Link the executable to the libraries we want to use (SO name of the library, without the "lib" prefix and the ".so" suffix)
target_link_libraries(RayTracer PUBLIC RayTracerLib)

# Set the directory where the header files are stored
target_include_directories(RayTracer PUBLIC ${CMAKE_SOURCE_DIR}/src) 

