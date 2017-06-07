#pragma once

#include <vector>
#include <set>
#include <functional>
#include <memory>

#include "Consts.h"

using gene=unsigned char;
using Chromosome = std::array<gene, CHROMOSOME_SIZE>;

using FValue = int;
using FitnessFunction = FValue(*)(const Chromosome &);

using WeightValue = double;
using WeighterFunction = WeightValue(*)(const FValue &);

using IsBetterFunction = bool (*)(const FValue &, const FValue &);

// TODO you may want WeighterFunc

class Population
{
public:
    Population()
    {
        individuals = {};
    }

    // TODO think, maybe it can be unordered_set, but Roulette algo...
    std::array<Chromosome, POPULATION_SIZE> individuals;
};
