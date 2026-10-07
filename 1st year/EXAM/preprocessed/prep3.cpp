#include <iostream>

int main (){
    #ifndef DEBUG 
    std::cout << "Release Mode" << std::endl;
    #else
    std::cout << "Debug Mode";
    #endif
}