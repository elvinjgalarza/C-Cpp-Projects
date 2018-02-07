cmake_minimum_required(VERSION 3.6)
project(Project_5__String_ADT_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Proj5Test.c
        String.c
        String.h)

add_executable(Project_5__String_ADT_ ${SOURCE_FILES})