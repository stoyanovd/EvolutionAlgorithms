#include <iostream>

#include "BasicEvolutions/Evolution.h"
#include "BasicEvolutions/CustomFunctions.h"

int main()
{
    Go(plainBinaryFitness, plainIdentityWeighter, true);

    Go(plainBinaryFitness, plainInverseWeighter, true);

    std::cout << "Finish." << std::endl;
    return 0;
}