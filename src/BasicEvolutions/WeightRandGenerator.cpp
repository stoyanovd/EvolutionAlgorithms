#include "WeightRandGenerator.h"

#include <algorithm>
#include <cassert>

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
