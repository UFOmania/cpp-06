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
        case 1:
            return new A;
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
        std::cout << "ptr is A -> : " << a->addTwo(13, 39) << std::endl;
        return;
    }

    B * b = dynamic_cast<B *>(ptr);
    if (b)
    {
        std::string str("hello world");
        b->toUpper(str);
        std::cout << "ptr is B -> : " << str << std::endl;
        return;
    }

    C * c = dynamic_cast<C *>(ptr);
    if (c)
    {
        std::cout << "ptr is C -> : ";
        c->sayHi();
        return;
    }
}

void    indentify(Base & obj)
{
    try
    {
        A a = dynamic_cast<A &>(obj);
        std::cout << "obj is A -> : " << a.addTwo(13, 29) << std::endl;
    }
    catch(const std::exception& )
    {}
    try
    {
        B b = dynamic_cast<B &>(obj);
        std::string str("hello world");
        b.toUpper(str);
        std::cout << "obj is B -> : " << str << std::endl;
    }
    catch(const std::exception& )
    {}
    try
    {
        C c = dynamic_cast<C &>(obj);
        std::cout << "obj is C -> : ";
        c.sayHi();
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