cmake_minimum_required(VERSION 3.7)

##############################################################################
include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.18.12.tar.gz"
        SHA1 "7e8c74787e08c476484d3e5106524fe7a5a0cc56"
)
##############################################################################

project(EvoAlgo)

set(CMAKE_CXX_STANDARD 14)

hunter_add_package(Sugar)
include("${SUGAR_ROOT}/cmake/Sugar")

##############################################################################
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

##############################################################################

#find_package(OpenMP)
#if (OPENMP_FOUND)
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#endif ()

include(sugar_include)
sugar_include("./src")

set(SOURCE_FILES
        main.cpp
        ${EvoAlgo_SOURCES}
        )

add_executable(EvoAlgo ${SOURCE_FILES})