#include <iostream>
#include "Serializer.hpp"



int main()
{
   
   Data data = {.n1 = 42, .n2 = 67};

   uintptr_t raw = Serializer::serialize(&data);

   Data *ptr = Serializer::deserialize(raw);

    std::cout << ptr->n1 << " <-> " << ptr->n2 << std::endl;
    std::cout << &data << "\n" << ptr << std::endl;
    
}