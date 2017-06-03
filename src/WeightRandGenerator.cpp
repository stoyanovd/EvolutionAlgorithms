#include "WeightRandGenerator.h"

#include <algorithm>
#include <cassert>
#include <numeric>

#include "Basis.h"

WeightRandGenerator::WeightRandGenerator(Population &p, FitnessFunction func)
{
    std::vector<FValue> fitness(p.individuals.size());
    for (auto individual : p.individuals)
    {
        fitness.push_back(func(individual));
    }
    for (int i = 0; i < p.individuals.size(); i++)
    {
        if (i == 0)
        {
            partial_sums.push_back(fitness[0]);
        }
        else
        { partial_sums.push_back(partial_sums[i - 1] + fitness[i]); }
    }
//    std::partial_sum(fitness.begin(), fitness.end(), partial_sums.begin());
}

size_t WeightRandGenerator::GetIndex()
{
    cur_double val = GetValue();
    for (size_t i = 0; i < partial_sums.size(); i++)
    {
        if (val <= partial_sums[i])
        {
            return i;
        }
    }

    // unpossible situation
    assert(false);
}

std::vector<size_t> WeightRandGenerator::GetMultipleIndex()
{
    size_t N = partial_sums.size();
    std::vector<cur_double> values(N);
    for (size_t i = 0; i < N; i++)
    {
        values.push_back(GetValue());
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
