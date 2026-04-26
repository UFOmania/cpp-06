#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>

#include <cstdlib>

Base *generate()
{

    int idx = (std::rand() % 3) + 1;

    switch (idx)
    {
        // case 1:
        //     return new A;
        case 2:
            return new B;
        case 3:
            return new C;
        default:
            return NULL;
    }
}


void    indentify(Base * ptr)
{
    if (!ptr)
        return ;
    
    A * a = dynamic_cast<A *>(ptr);
    if (a)
    {
        std::cout << "obj is A\n";
        return;
    }

    B * b = dynamic_cast<B *>(ptr);
    if (b)
    {
        std::cout << "obj is B\n";
        return;
    }

    C * c = dynamic_cast<C *>(ptr);
    if (c)
    {
        std::cout << "obj is C\n";
        return;
    }
}

void    indentify(Base & ptr)
{
    try
    {
        A a = dynamic_cast<A &>(ptr);
        std::cout << "obj is A\n";
    }
    catch(const std::exception& )
    {}
    try
    {
        B b = dynamic_cast<B &>(ptr);
        std::cout << "obj is B\n";
    }
    catch(const std::exception& )
    {}
    try
    {
        C c = dynamic_cast<C &>(ptr);
        std::cout << "obj is C\n";
    }
    catch(const std::exception& )
    {}
    
}

int main()
{
    std::srand(time(0));


    for (int i = 0; i < 5; i++)
    {
        Base * b = generate();
        indentify(b);
        delete b;
    }

    std::cout << "\n";

    for (int i = 0; i < 5; i++)
    {
        Base * b = generate();
        indentify(*b);
        delete b;
    }
}