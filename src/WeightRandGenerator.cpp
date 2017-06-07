#include "WeightRandGenerator.h"

#include <algorithm>
#include <cassert>

WeightRandGenerator::WeightRandGenerator(const Population &p, FitnessFunction func)
{
    std::vector<FValue> fitness;
    fitness.reserve(p.individuals.size());
    for (const auto &individual : p.individuals)
    {
//        fitness.push_back((*func.get())(individual));
        fitness.push_back(func(individual));
    }
    for (int i = 0; i < (int)p.individuals.size(); i++)
    {
        if (i == 0)
        {
            partial_sums.push_back((FValue_double) fitness[0]);
        }
        else
        { partial_sums.push_back(partial_sums[i - 1] + (FValue_double) fitness[i]); }
    }
}

std::vector<size_t> WeightRandGenerator::GetMultipleIndex()
{
    size_t N = partial_sums.size();
    std::vector<FValue_double> values;
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
