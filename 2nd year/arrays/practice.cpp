#include <iostream>
#include <array>

struct String{
    int charsString;
};

struct File{
    std::array< String, 5 > strings;
};

void addChars(File* file, int index, int addedChars)
{
    file->strings[index].charsString += addedChars;
}

void swap (File* file, int firstIndex, int secondIndex)
{
    int temp;
    temp = file->strings[firstIndex].charsString;
    file->strings[firstIndex].charsString = file->strings[secondIndex].charsString;
    file->strings[secondIndex].charsString = temp;
}

int main()
{
    File file{2, 5, 10, 7, 6};

    std::cout << file.strings[0].charsString << std::endl;

    addChars(&file, 0, 10);
    std::cout << file.strings[0].charsString << std::endl;

    std::cout << file.strings[1].charsString << std::endl;
    std::cout << file.strings[3].charsString << std::endl;
    
    swap(&file, 1, 3);
    std::cout << file.strings[1].charsString << std::endl;
    std::cout << file.strings[3].charsString << std::endl;
}