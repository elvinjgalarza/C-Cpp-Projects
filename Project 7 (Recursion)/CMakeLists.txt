cmake_minimum_required(VERSION 3.6)
project(Project_7__Recursion_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Recursive.c
        Recursive.h
        RecursiveTester.c)

add_executable(Project_7__Recursion_ ${SOURCE_FILES})