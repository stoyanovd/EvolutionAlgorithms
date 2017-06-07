#pragma once

#include <vector>
#include <set>
#include <functional>
#include <memory>

#include "Consts.h"

using gene=unsigned char;

template<int C>
using Chromosome = std::array<gene, C>;

using FValue = int;

template<int C>
using FitnessFunction = FValue(*)(const Chromosome<C> &);

using WeightValue = double;

using WeighterFunction = WeightValue(*)(const FValue &);

//using IsBetterFunction = bool (*)(const FValue &, const FValue &);

template<int C, int P>
class Population
{
public:
    Population()
    {
        individuals = {};
    }
    std::array<Chromosome<C>, P> individuals;
};
