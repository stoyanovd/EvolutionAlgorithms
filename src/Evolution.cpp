#include <iostream>
#include "Evolution.h"
#include "Basis.h"
#include "Operations.h"
#include "CustomFunctions.h"

Chromosome CreateRandomChromosome()
{
    Chromosome c;
    for (auto &x : c)
    {
        x = (gene) (rand() % 2);
    }
    return c;
}

Population CreateRandomPopulation()
{
    Population p{};
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        p.individuals[i] = CreateRandomChromosome();
    }
    return p;
}

int GetBest(Population &p, FitnessFunction func)
{
    int best = -1;
    FValue best_value = 0;
    for (int i = 0; i < p.individuals.size(); i++)
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
    Population population = CreateRandomPopulation();
    FitnessFunction func = plainMaximumFitness;

    for (int i = 0; i < EPOCHS_NUMBER; i++)
    {
        std::cout << "i: " << i << std::endl;
        population = Reproduction(population, func);
        Crossingover(population);
        Mutation(population);
    }

    int best = GetBest(population, func);

    std::cout << "Best value: " << func(population.individuals[best]) << std::endl;
    for (auto g : population.individuals[best])
    {
        std::cout << (g == 1 ? "1" : "0") << std::endl;
    }
}
