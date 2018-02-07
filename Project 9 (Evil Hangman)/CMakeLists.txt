cmake_minimum_required(VERSION 3.6)
project(Project_9__Evil_Hangman_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        dictionary.txt
        EvilHangmanGame.cpp
        EvilHangmanGame.h
        RunEvilHangman.cpp
        smallDictionary.txt)

add_executable(Project_9__Evil_Hangman_ ${SOURCE_FILES})