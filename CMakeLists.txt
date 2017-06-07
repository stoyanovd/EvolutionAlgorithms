cmake_minimum_required(VERSION 3.7)
project(EvoAlgo)

set(CMAKE_CXX_STANDARD 14)

################################################################################
#unset(CMAKE_CXX_FLAGS CACHE)
if (CMAKE_COMPILER_IS_GNUCXX)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall" CACHE STRING COMPILE_FLAGS FORCE)
    #    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g" CACHE STRING COMPILE_FLAGS FORCE)

    set(CMAKE_CXX_FLAGS_RELEASE
            "${CMAKE_CXX_FLAGS} -O3 -g -march=native --fast-math -ffast-math -mtune=native -funroll-loops -DNDEBUG -DBOOST_DISABLE_ASSERTS"
            CACHE STRING COMPILE_FLAGS FORCE)

    set(CMAKE_CXX_FLAGS_DEBUG
            "${CMAKE_CXX_FLAGS} -O0 -g -DDEBUG"
            CACHE STRING COMPILE_FLAGS FORCE)

    add_definitions(-D__STDC_CONSTANT_MACROS)

else ()
    message(FATAL_ERROR "CXX_FLAGS for this compiler are untuned")
endif ()
################################################################################

#find_package(OpenMP)
#if (OPENMP_FOUND)
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#endif ()

set(SOURCE_FILES
        main.cpp
        src/Operations.cpp
        src/Basis.h
        src/WeightRandGenerator.cpp
        src/WeightRandGenerator.h
        src/Evolution.cpp
        src/Evolution.h
        src/Consts.h
        src/CustomFunctions.h
        src/CustomFunctions.cpp
        src/Operations.h)

add_executable(EvoAlgo ${SOURCE_FILES})