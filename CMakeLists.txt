cmake_minimum_required(VERSION 3.16)
project(Complex)

set(CMAKE_CXX_STANDARD 14)

add_executable(Complex project1main.cpp Complex.h Complex.cpp ComplexDB.cpp ComplexDB.h)