cmake_minimum_required(VERSION 3.17)
project(StaticLib)

set(CMAKE_CXX_STANDARD 14)

add_library(StaticLib STATIC staticlb.cpp staticlb.h)