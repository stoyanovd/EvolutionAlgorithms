#pragma once

#include "Basis.h"

inline double GetRandInOne()
{
    return (double) rand() / RAND_MAX;
}

class WeightRandGenerator
{
public:

    template<int C, int P>
    WeightRandGenerator(const Population<C, P> &p, FitnessFunction<C> fitness, WeighterFunction weighter);

    std::vector<size_t> GetMultipleIndex();

private:
    inline WeightValue GetRandInPartialMax()
    {
        return partial_sums.back() * GetRandInOne();
    }

    std::vector<WeightValue> partial_sums;
};

#include "WeightRandGenerator.tpp"
