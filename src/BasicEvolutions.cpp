#include <iostream>

#include "BasicEvolutions/Evolution.h"
#include "BasicEvolutions/CustomFunctions.h"
#include "BasicEvolutions/Evolution.tpp"

//constexpr std::array<int, 2> Cc = {0, 20};
constexpr int C = 10;

constexpr std::array<int, 3> Pp = {20, 50, 100};

template<int I>
void iterate_over(const decltype(Pp) &a)
{
    Go<C, Pp[I]>(plainBinaryFitness<C>, plainIdentityWeighter, true);

    if constexpr (I + 1 < a.size())
    {
        iterate_over<I + 1>(a);
    }
}

int main()
{
//    const int C = 10;
//    const int P = 500;
//    Go<C, P>(plainBinaryFitness<C>, plainIdentityWeighter, true);
//    Go<C, P>(plainBinaryFitness<C>, plainInverseWeighter, true);

    iterate_over<0>(Pp);

    std::cout << "Finish." << std::endl;
    return 0;
}