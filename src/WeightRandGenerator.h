#pragma once

#include "Basis.h"

class WeightRandGenerator
{
public:
    WeightRandGenerator(const Population &p, FitnessFunction func);

    std::vector<size_t> GetMultipleIndex();

    using FValue_double = double;

private:
    inline FValue_double GetRandInPartialMax()
    {
        return (FValue_double) rand() / RAND_MAX * partial_sums.back();
    }

    std::vector<FValue_double> partial_sums;
};

inline double GetRandInOne()
{
    return (double) rand() / RAND_MAX;
}