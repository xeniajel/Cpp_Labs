#include <iostream>
void c(){
    std::cout <<"Called 'c'" << std::endl;
}
void b() {
    std::cout <<"Called 'b'" << std::endl;
}

void a(){
    std::cout <<"Called 'a'" <<std::endl;
    b();
    c();
}

int main(){
    a();
    b();
    c();
}