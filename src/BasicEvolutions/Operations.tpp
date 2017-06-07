#pragma once

#include "WeightRandGenerator.h"


template<int C, int P>
Population<C, P> Reproduction(Population<C, P> &p, FitnessFunction<C> func, WeighterFunction weighter)
{
    WeightRandGenerator generator(p, func, weighter);
    auto indexes = generator.GetMultipleIndex();

    Population<C, P> result{};
    int j = 0;
    for (auto i : indexes)
    {
        result.individuals[j] = p.individuals[i];
        j++;
    }
    return result;
}

template<int C>
void ExchangeGenes(Chromosome<C> &a, Chromosome<C> &b, int sep_point)
{
    std::swap_ranges(a.begin() + sep_point, a.end(), b.begin() + sep_point);
}

template<int C, int P>
void Crossingover(Population<C, P> &p)
{
    for (int i = 0; i < CROSSINGOVERS_NUMBER; i++)
    {
        if (GetRandInOne() > CROSSINGOVERS_PROBABILITY)
        {
            continue;
        }
        int first = rand() % P;
        int second = rand() % P;
        int sep_point = rand() % C;
        ExchangeGenes<C>(p.individuals[first], p.individuals[second], sep_point);
    }
}

template<int C, int P>
void Mutation(Population<C, P> &p)
{
    for (auto &individual : p.individuals)
    {
        if (GetRandInOne() > MUTATION_PROBABILITY)
        {
            continue;
        }
        int sep_point = rand() % C;
        individual[sep_point] = (gene) (!individual[sep_point]);
    }
}