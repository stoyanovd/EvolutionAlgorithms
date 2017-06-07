#include "CustomFunctions.h"

WeighterFunction plainIdentityWeighter = [](const FValue &v)
{
    return static_cast<WeightValue>(v);
};

WeighterFunction plainInverseWeighter = [](const FValue &v)
{
    return static_cast<WeightValue>(1.0 / (v + 1));
};
