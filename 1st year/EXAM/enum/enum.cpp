#include <iostream>
    enum order {CREATED, PAID, SHIPPED, DELIVERED};
int main() {
    order k = PAID;
    switch (k) {
    case CREATED: std::cout << "The order is created";
        break;
    case PAID: std::cout << "The order is paid";
        break;
    case SHIPPED: std::cout << "The order is shipped";
        break;
    case DELIVERED: std::cout << "The order is delivered";
    }
}