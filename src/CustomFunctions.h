#pragma once

#include "Basis.h"

FitnessFunction plainMaximumFitness = [](Chromosome &c)
{
    FValue sum = 0;
    for (auto g = c.rbegin(); g != c.rend(); g++)
    {
        sum = sum * 2 + *g;
    }
    return sum;
};

