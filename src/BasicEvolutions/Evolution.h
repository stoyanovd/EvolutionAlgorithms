#pragma once

#include "Basis.h"

template<int C, int P>
void Go(FitnessFunction<C> func, WeighterFunction weighter, bool output);

#include "Evolution.tpp"