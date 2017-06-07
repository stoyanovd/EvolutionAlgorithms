#pragma once

template<int C>
FitnessFunction<C> plainBinaryFitness = [](const Chromosome<C> &c)
{
    FValue sum = 0;
    for (auto g = c.begin(); g != c.end(); g++)
    {
        sum = sum * 2 + *g;
    }
    return sum;
};
