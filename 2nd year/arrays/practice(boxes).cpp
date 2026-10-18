#include <iostream>
#include <array>

struct Box{
    int screwsCount;
};

struct Closet{
    std::array<Box, 4> boxes;
};

void swap(Closet* closet, int selectedBox, int emptyBox)
{
    int temp;
    temp = closet->boxes[emptyBox].screwsCount;
    closet->boxes[emptyBox].screwsCount = closet->boxes[selectedBox].screwsCount;
    closet->boxes[selectedBox].screwsCount = temp;
}

int main(){
    Closet closet{5, 0, 3, 2};

    std::cout << closet.boxes[0].screwsCount << std::endl;
    std::cout << closet.boxes[1].screwsCount << std::endl;
    swap(&closet, 0, 1);

    std::cout << closet.boxes[0].screwsCount << std::endl;
    std::cout << closet.boxes[1].screwsCount << std::endl;
}