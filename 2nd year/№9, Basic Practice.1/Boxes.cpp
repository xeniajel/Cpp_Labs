#include <iostream>

struct StoreRoom{
    int totalItems;
    int boxCapacity;
};

struct PackingResult
{
    int fullBoxes;
    int leftoverItems;
};

PackingResult pack_boxes(StoreRoom store)
{
    return PackingResult{
        .fullBoxes = store.totalItems / store.boxCapacity,
        .leftoverItems = store.totalItems % store.boxCapacity,
    };
}

int main(){
    StoreRoom store{
        .totalItems = 48,
        .boxCapacity = 10,
    };

    PackingResult result{ pack_boxes(store) };

    std::cout << "Full boxes: " << result.fullBoxes << std::endl;
    std::cout << "Leftover items: " << result.leftoverItems << std::endl;
}