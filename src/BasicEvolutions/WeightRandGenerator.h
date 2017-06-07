#pragma once

#include "Basis.h"

inline double GetRandInOne()
{
    return (double) rand() / RAND_MAX;
}

class WeightRandGenerator
{
public:

    WeightRandGenerator(const Population &p, FitnessFunction fitness, WeighterFunction weighter);

    std::vector<size_t> GetMultipleIndex();

private:
    inline WeightValue GetRandInPartialMax()
    {
        return partial_sums.back() * GetRandInOne();
    }

    std::vector<WeightValue> partial_sums;
};
