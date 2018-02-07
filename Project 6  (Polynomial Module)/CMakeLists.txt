cmake_minimum_required(VERSION 3.6)
project(Project_6___Polynomial_Module_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Poly.c
        Poly.h
        Proj6Test.c)

add_executable(Project_6___Polynomial_Module_ ${SOURCE_FILES})