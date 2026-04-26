#include <iostream>
#include "ScalarConverter.hpp"



int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Invalid argument count. 'PROGRAM_NAME <INPUT>'";
        return 1;
    }

    ScalarConverter::convert(av[1]);
    
}