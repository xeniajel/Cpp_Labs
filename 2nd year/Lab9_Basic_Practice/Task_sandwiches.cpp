#include <cmath>
#include <iostream>

struct Fridge{
    int loafBread;
    int cheeseGr;
};

struct SandwichesRecipeConfiguration{
    int loafBreadPerPortion;
    int cheeseGrPerPortion;
};

int cook_sandwiches (Fridge* fridge, SandwichesRecipeConfiguration config)
{
    int a {fridge->loafBread/config.loafBreadPerPortion};
    int b {fridge->cheeseGr/config.cheeseGrPerPortion};
    int p {std::min(a,b)};
    int result {p};
    fridge->loafBread -= p*config.loafBreadPerPortion;
    fridge->cheeseGr -= p*config.cheeseGrPerPortion;
    return result;
}

int main()
{
    Fridge fridge
    {
        .loafBread = 7,
        .cheeseGr = 100,
    };

    SandwichesRecipeConfiguration config{
        .loafBreadPerPortion = 2,
        .cheeseGrPerPortion = 30,
    };

    int preparedSandwichesCount {cook_sandwiches(&fridge, config)};

std::cout 
        << "Cooked " 
        << preparedSandwichesCount 
        << " sandwiches" 
        << std::endl;
    std::cout 
        << "Left "
        << fridge.loafBread
        << " bread and " 
        << fridge.cheeseGr
        << " gram of cheeese in the fridge"
        << std::endl;
}