set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# To generate the .dll file
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Set the library output directory
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Set the output executable name, and the source files to be compiled
add_library(RayTracerLib SHARED
Camera.hpp Camera.cpp
constants.hpp
Drawer.cpp Drawer.hpp
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
target_link_libraries(RayTracerLib PUBLIC SDL2 SDL2main SDL2_image)

# Set the directory where the libraries are stored
target_link_directories(RayTracerLib PUBLIC ${CMAKE_SOURCE_DIR}/external/SDL2_image/lib/x64/  ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x64)

# Set the directory where the header files are stored
target_include_directories(RayTracerLib PUBLIC ${CMAKE_SOURCE_DIR}/external/SDL2_image/include/ ${CMAKE_SOURCE_DIR}/external/SDL2/include/) 


add_subdirectory(launcher)

