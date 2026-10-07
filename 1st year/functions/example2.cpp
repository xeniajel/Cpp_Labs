#include <iostream>

struct Client {
    int adrink;
    int afirst;
    int asecond;
};

struct Price {
    int drink;
    int first;
    int second; 
};

int Order (Price a, Client b){
 return b.adrink * a.drink + b.afirst * a.first + b.asecond * a.second; 
}

void Print(std::string_view clientNum, int final)
    {
        std::cout << "The " << clientNum << " client's price: " << final << std::endl;
    }

int main () {
    Price prices {
        .drink = 10,
        .first = 20,
        .second = 30,
    };

    {
        Client client {1, 2, 1}; 
        
        int final = Order(prices, client);
        Print("first",final);
    }

    {
        Client client {5, 4, 2};

        int final = Order(prices, client);
        Print("second",final);
    }
}