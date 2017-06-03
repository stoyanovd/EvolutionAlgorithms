#pragma once

#include "Basis.h"

class WeightRandGenerator
{
public:
    WeightRandGenerator(Population &p, FitnessFunction func);

    size_t GetIndex();
    std::vector<size_t> GetMultipleIndex();

    using cur_double = FValue ;

private:
    inline cur_double GetValue()
    {
        return (cur_double) rand() / RAND_MAX * partial_sums.back();
    }

    std::vector<cur_double> partial_sums;
};

inline double GetRandInOne()
{
    return (double) rand() / RAND_MAX;
}