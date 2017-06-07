#pragma once

#include "Basis.h"

template<int C, int P>
Population<C, P> Reproduction(Population<C, P> &p, FitnessFunction<C> func, WeighterFunction weighter);

template<int C, int P>
void Crossingover(Population<C, P> &p);

template<int C, int P>
void Mutation(Population<C, P> &p);

#include "Operations.tpp"
