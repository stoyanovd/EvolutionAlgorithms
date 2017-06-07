#pragma once

#include "Basis.h"

Population Reproduction(Population &p, FitnessFunction func, WeighterFunction weighter);

void Crossingover(Population &p);

void Mutation(Population &p);
