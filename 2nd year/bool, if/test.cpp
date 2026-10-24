#include <iostream>

int main()
{
   int *a{nullptr};
   if (a)
   {
      std::cout << "a is true" << std::endl;
   }

   int b;
   int *pb{&b};
   if (pb)
   {
      std::cout << "pb is true" << std::endl;
   }
   if (b)
   {
      std::cout << "b is true" << std::endl;
   }

   bool c{false};
   bool *pc{&c};
   if (pc)
   {
      std::cout << "pc is true" << std::endl;
   }
}