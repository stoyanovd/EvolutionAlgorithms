#pragma once

#include "Basis.h"

Population Reproduction(Population &p, FitnessFunction func);

void Crossingover(Population &p);

void Mutation(Population &p);
