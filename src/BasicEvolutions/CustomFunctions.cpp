#include "CustomFunctions.h"

FitnessFunction plainBinaryFitness = [](const Chromosome &c)
{
    FValue sum = 0;
    for (auto g = c.begin(); g != c.end(); g++)
    {
        sum = sum * 2 + *g;
    }
    return sum;
};

WeighterFunction plainIdentityWeighter = [](const FValue &v)
{
    return static_cast<WeightValue>(v);
};

WeighterFunction plainInverseWeighter = [](const FValue &v)
{
    return static_cast<WeightValue>(1.0 / (v + 1));
};
