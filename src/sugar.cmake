if (DEFINED EvoAlgo_src_sugar)
    return()
else ()
    set(EvoAlgo_src_sugar 1)
endif ()

include(sugar_include)
include(sugar_files)

sugar_files(EvoAlgo_SOURCES
        Operations.cpp
        Basis.h
        WeightRandGenerator.cpp
        WeightRandGenerator.h
        Evolution.cpp
        Evolution.h
        Consts.h
        CustomFunctions.h
        CustomFunctions.cpp
        Operations.h
        )
