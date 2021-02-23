cmake_minimum_required(VERSION 3.17)
project(libraries)

set(CMAKE_CXX_STANDARD 14)

include_directories(Dynamic_Implicit Static_lib)

add_executable(libraries main.cpp)

add_subdirectory(Dynamic_Implicit)
add_subdirectory(Dynamic_explicit)
add_subdirectory(Static_lib)

target_link_libraries(libraries Dimplicit StaticLib)