cmake_minimum_required(VERSION 3.17)
project(Dimplicit)

set(CMAKE_CXX_STANDARD 14)

add_library(Dimplicit SHARED DynSortImp.cpp DynSortImp.h)