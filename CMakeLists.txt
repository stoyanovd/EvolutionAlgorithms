cmake_minimum_required(VERSION 3.7)
project(EvoAlgo)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        src/Operations.cpp
        src/Basis.cpp
        src/Basis.h
        src/WeightRandGenerator.cpp
        src/WeightRandGenerator.h src/Evolution.cpp src/Evolution.h src/Consts.h src/CustomFunctions.h src/Operations.h)

add_executable(EvoAlgo ${SOURCE_FILES})