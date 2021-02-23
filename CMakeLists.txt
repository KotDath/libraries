cmake_minimum_required(VERSION 3.17)
project(libraries)

set(CMAKE_CXX_STANDARD 14)

include_directories(Dynamic_lib Static_lib)

add_executable(libraries main.cpp)

add_subdirectory(Dynamic_lib)
add_subdirectory(Static_lib)

target_link_libraries(libraries Dynamic StaticLib)