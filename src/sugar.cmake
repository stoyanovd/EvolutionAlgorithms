if (DEFINED EvoAlgo_src_sugar)
    return()
else ()
    set(EvoAlgo_src_sugar 1)
endif ()

include(sugar_include)
include(sugar_files)

sugar_include("./BasicEvolutions")

sugar_files(BasicEvolutions_SOURCES
        BasicEvolutions.cpp)
