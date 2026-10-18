#include <iostream>
#include <array>

struct Product
{
    int price;
    int quantity;
};

struct Minibar
{
    std::array<Product, 4> cells;
    int bill;
};

void takeProduct(Minibar* minibar, int fisrtCell, int secondCell, int quantity1, int quantity2)
{
    minibar->cells[fisrtCell].quantity -= quantity1;
    minibar->cells[secondCell].quantity -= quantity2;

    minibar->bill += minibar->cells[fisrtCell].price * quantity1 
    + minibar->cells[secondCell].price * quantity2;
}

int main()
{
    Minibar minibar{
        {{{10, 5}, {20, 3}, {15, 8}, {25, 4}}},
        0
    };

    takeProduct(&minibar, 0, 1, 2, 3);

    std::cout << "First cell: "
              << minibar.cells[0].quantity << '\n';

    std::cout << "Second cell: "
              << minibar.cells[1].quantity << '\n';

    std::cout << "Bill: " << minibar.bill << '\n';

    return 0;
}