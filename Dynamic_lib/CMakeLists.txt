cmake_minimum_required(VERSION 3.17)
project(Dynamic)

set(CMAKE_CXX_STANDARD 14)

add_library(Dynamic SHARED DynSort.cpp DynSort.h)