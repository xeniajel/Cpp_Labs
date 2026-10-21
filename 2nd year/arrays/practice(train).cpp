#include <iostream>
#include <array>

struct Vagon
{
    int passangers;
    int capacity;
};

struct Train
{
    std::array<Vagon, 3> vagons;
};

void movePassengers(Train *train, int fromVagon, int toVagon)
{
    train->vagons[toVagon].passangers += train->vagons[fromVagon].passangers;
    train->vagons[fromVagon].passangers = 0;
}

int emptySeats(Train train, int selectedVagon)
{
    return train.vagons[selectedVagon].capacity - train.vagons[selectedVagon].passangers;
}

int main()
{
    Train train{
        .vagons = {
            Vagon{10, 20},
            {5, 20},
            {30, 30},
        }
    };

    std::cout << train.vagons[0].passangers << std::endl;
    std::cout << train.vagons[1].passangers << std::endl;

    movePassengers(&train, 0, 1);

    std::cout << train.vagons[0].passangers << std::endl;
    std::cout << train.vagons[1].passangers << std::endl;

    int emptySeats1 = emptySeats(train, 0);
    int emptySeats2 = emptySeats(train, 1);

    std::cout << "Empty seats in 1st: " << emptySeats1 << std::endl;
    std::cout << "Empty seats in 2nd: " << emptySeats2 << std::endl;
}