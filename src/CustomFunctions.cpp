#include "CustomFunctions.h"

FitnessFunction plainMaximumFitness = [](const Chromosome &c)
{
    FValue sum = 0;
    for (auto g = c.begin(); g != c.end(); g++)
    {
        sum = sum * 2 + *g;
    }
    return sum;
};
