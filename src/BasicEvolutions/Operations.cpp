#include "Operations.h"

#include "WeightRandGenerator.h"

Population Reproduction(Population &p, FitnessFunction func, WeighterFunction weighter)
{
    WeightRandGenerator generator(p, func, weighter);
    auto indexes = generator.GetMultipleIndex();

    Population result{};
    int j = 0;
    for (auto i : indexes)
    {
        result.individuals[j] = p.individuals[i];
        j++;
    }
    return result;
}

void ExchangeGenes(Chromosome &a, Chromosome &b, size_t sep_point)
{
    std::swap_ranges(a.begin() + sep_point, a.end(), b.begin() + sep_point);
}

void Crossingover(Population &p)
{
    for (int i = 0; i < CROSSINGOVERS_NUMBER; i++)
    {
        if (GetRandInOne() > CROSSINGOVERS_PROBABILITY)
        {
            continue;
        }
        size_t first = rand() % p.individuals.size();
        size_t second = rand() % p.individuals.size();
        size_t sep_point = rand() % CHROMOSOME_SIZE;
        ExchangeGenes(p.individuals[first], p.individuals[second], sep_point);
    }
}

void Mutation(Population &p)
{
    for (auto &individual : p.individuals)
    {
        if (GetRandInOne() > MUTATION_PROBABILITY)
        {
            continue;
        }
        size_t sep_point = rand() % CHROMOSOME_SIZE;
        individual[sep_point] = (gene) (!individual[sep_point]);
    }
}