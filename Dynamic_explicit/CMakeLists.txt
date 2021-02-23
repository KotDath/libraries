cmake_minimum_required(VERSION 3.17)
project(Dexplicit)

set(CMAKE_CXX_STANDARD 14)

add_library(Dexplicit SHARED DynSortExp.cpp DynSortExp.h)