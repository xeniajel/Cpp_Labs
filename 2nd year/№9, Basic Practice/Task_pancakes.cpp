#include <algorithm>
#include <iostream>

struct Fridge
{
    int eggCount;
    int kefirMl;
};

struct PancakesRecipeConfiguration
{
    int pancakesPerPortion;
    int kefirMlUsedPerPortion;
};

int cook_pancakes(Fridge* fridge, PancakesRecipeConfiguration config)
{
    int a { fridge->eggCount };
    int b { fridge->kefirMl / config.kefirMlUsedPerPortion };
    int p { std::min(a, b) };
    int result { p * config.pancakesPerPortion };
    fridge->eggCount -= p; 
    fridge->kefirMl -= p * config.kefirMlUsedPerPortion;
    return result;
}

int main()
{
    Fridge fridge{
        .eggCount = 6,
        .kefirMl = 1100,
    };

    PancakesRecipeConfiguration config{
        .pancakesPerPortion = 8,
        .kefirMlUsedPerPortion = 250,
    };
    int preparedPancakeCount{ cook_pancakes(&fridge, config) };

    std::cout 
        << "Cooked " 
        << preparedPancakeCount 
        << " pancakes" 
        << std::endl;
    std::cout 
        << "Left "
        << fridge.eggCount 
        << " eggs and " 
        << fridge.kefirMl
        << "ml of kefir in the fridge"
        << std::endl;
}