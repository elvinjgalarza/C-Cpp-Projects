cmake_minimum_required(VERSION 3.6)
project(Project_10__War_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        playWar.cpp)

add_executable(Project_10__War_ ${SOURCE_FILES})