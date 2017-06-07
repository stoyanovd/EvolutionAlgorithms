#include "WeightRandGenerator.h"

#include <algorithm>
#include <cassert>

WeightRandGenerator::WeightRandGenerator(const Population &p, FitnessFunction fitness, WeighterFunction weighter)
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

std::vector<size_t> WeightRandGenerator::GetMultipleIndex()
{
    size_t N = partial_sums.size();
    std::vector<WeightValue> values;
    values.reserve(N);

    for (size_t i = 0; i < N; i++)
    {
        values.push_back(GetRandInPartialMax());
    }
    sort(values.begin(), values.end());

    std::vector<size_t> ans;
    size_t index = 0;
    for (auto v : values)
    {
        while (v > partial_sums[index])
        {
            index++;
        }
        ans.push_back(index);
    }
    return ans;
}
