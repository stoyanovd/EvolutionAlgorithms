#include <iostream>
#include <cassert>

#include "Evolution.h"
#include "Basis.h"
#include "Operations.h"
#include "CustomFunctions.h"

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
    Population p = {};
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        p.individuals[i] = CreateRandomChromosome();
    }
    return std::move(p);
}

int GetBest(const Population &p, FitnessFunction func)
{
    int best = -1;
    FValue best_value = 0;
    for (int i = 0; i < (int) p.individuals.size(); i++)
    {
        FValue x = func(p.individuals[i]);
        if (best == -1 || best_value < x)
        {
            best = i;
            best_value = x;
        }
    }
    return best;
}

void Go()
{
    std::cout << "Start evolution:" << std::endl;
    std::cout << "CHROMOSOME_SIZE: " << CHROMOSOME_SIZE << std::endl;
    std::cout << "POPULATION_SIZE: " << POPULATION_SIZE << std::endl;
    std::cout << "EPOCHS_NUMBER: " << EPOCHS_NUMBER << std::endl;

    srand(time(NULL));
    Population population = CreateRandomPopulation();
    FitnessFunction func = plainMaximumFitness;
//    ComparatorFunction comp = ;

    for (int i = 0; i < EPOCHS_NUMBER; i++)
    {
        if (i * 10 % EPOCHS_NUMBER == 0)
        {
            std::cout << "done " << i * 100 / EPOCHS_NUMBER << "%" << std::endl;
        }
        population = Reproduction(population, func);
        Crossingover(population);
        Mutation(population);
    }

    int best = GetBest(population, func);

    assert(best != -1);

    std::cout << "Best value: " << func(population.individuals[best]) << std::endl;
    std::cout << "Individual: " << std::endl;
    for (auto g : population.individuals[best])
    {
        std::cout << (g == 1 ? "1" : "0");
    }
    std::cout << std::endl;
}
