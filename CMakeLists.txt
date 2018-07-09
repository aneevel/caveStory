cmake_minimum_required (VERSION 3.10 FATAL_ERROR)
project ( cavestory VERSION 0.1 LANGUAGES CXX )

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

# Add game source libraries
add_library(game src/game.cpp)
add_library(graphics src/graphics.cpp)
add_library(sprite src/sprite.cpp src/animated_sprite.cpp)

# Find SDL

find_package(SDL REQUIRED)

INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})

# Build compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

# create executable
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} game graphics sprite ${SDL_LIBRARY})
