#pragma once

#include <vector>
#include <set>
#include <functional>
#include "Consts.h"

using gene=unsigned char;
using Chromosome = std::array<gene, CHROMOSOME_SIZE>;

using FValue = int;
using FitnessFunction = std::function<FValue(Chromosome &)>;

class Population
{
public:
    // TODO think, maybe it can be unordered_set, but Roulette algo...
    std::array<Chromosome, POPULATION_SIZE> individuals;
};
