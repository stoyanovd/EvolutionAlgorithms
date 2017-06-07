#include <iostream>

#include "Evolution.h"
#include "Operations.h"

Chromosome CreateRandomChromosome()
{
    Chromosome c = {};
    for (auto &x : c)
    {
        x = (gene) (rand() % 2);
    }
    return std::move(c);
}

Population CreateRandomPopulation()
{
    srand(time(NULL));
    Population p = {};
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        p.individuals[i] = CreateRandomChromosome();
    }
    return std::move(p);
}

int GetBest(const Population &p, FitnessFunction func, WeighterFunction weighter)
{
    int best = -1;
    WeightValue best_weight = 0;
    for (int i = 0; i < (int) p.individuals.size(); i++)
    {
        FValue x = func(p.individuals[i]);
        WeightValue w = weighter(x);
        if (best == -1 || best_weight < w)
        {
            best = i;
            best_weight = w;
        }
    }
    return best;
}

void Go(FitnessFunction func, WeighterFunction weighter, bool output)
{
    if (output)
    {
        std::cout << "Start evolution:" << std::endl;
        std::cout << "CHROMOSOME_SIZE: " << CHROMOSOME_SIZE << std::endl;
        std::cout << "POPULATION_SIZE: " << POPULATION_SIZE << std::endl;
        std::cout << "EPOCHS_NUMBER: " << EPOCHS_NUMBER << std::endl;
    }

    Population population = CreateRandomPopulation();

    for (int i = 0; i < EPOCHS_NUMBER; i++)
    {
//        if (i * 10 % EPOCHS_NUMBER == 0)
//        {
//            std::cout << "done " << i * 100 / EPOCHS_NUMBER << "%" << std::endl;
//        }
        population = Reproduction(population, func, weighter);
        Crossingover(population);
        Mutation(population);
    }

    int best = GetBest(population, func, weighter);

    if (best == -1)
    { throw new std::exception(); }

    if (output)
    {
        std::cout << "Best value: " << func(population.individuals[best]) << std::endl;
        std::cout << "Individual: " << std::endl;
        for (auto g : population.individuals[best])
        {
            std::cout << (g == 1 ? "1" : "0");
        }
        std::cout << std::endl;
    }
}
