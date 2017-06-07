#pragma once

#include <algorithm>
#include <cassert>

template<int C, int P>
WeightRandGenerator::WeightRandGenerator(const Population<C, P> &p,
                                         FitnessFunction<C> fitness,
                                         WeighterFunction weighter)
{
    std::vector<WeightValue> weights;
    weights.reserve(p.individuals.size());
    for (const auto &individual : p.individuals)
    {
        auto w = weighter(fitness(individual));
//        fitness.push_back((*fitness.get())(individual));
        weights.push_back(w);
    }
    for (int i = 0; i < (int) p.individuals.size(); i++)
    {
        if (i == 0)
        {
            partial_sums.push_back(weights[0]);
        }
        else
        {
            partial_sums.push_back(partial_sums[i - 1] + weights[i]);
        }
    }
}
