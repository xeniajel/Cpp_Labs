#include <iostream>
#include <array>

struct Recipe{
    int flourPerCake;
    int sugarPerCake;
};

struct Bakery{
    std::array<Recipe, 3> recipe;
};


struct Inventory{
    int flour;
    int sugar;
    int cakesMade;
};

void makeCake(Bakery* bakery, Inventory* inventory, int cakesNedeed, int recipeIndex)
{
    inventory->flour -= bakery->recipe[recipeIndex].flourPerCake * cakesNedeed;
    inventory->sugar -= bakery->recipe[recipeIndex].sugarPerCake * cakesNedeed;
    inventory->cakesMade += cakesNedeed;
}

int main()
{
    Bakery bakery{ { {
    {100, 10},
    {40, 30},
    {300, 50}
    } } };

    Inventory inventory {
        .flour = 1000,
        .sugar = 500,
    };

    makeCake(&bakery, &inventory, 10, 1);

    std::cout << "Cakes made: " << inventory.cakesMade << std::endl;
    std::cout << "Flour left: " << inventory.flour << "Sugar left: " << inventory.sugar << std::endl;
}