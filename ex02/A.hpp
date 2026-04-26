#ifndef A_HPP
#define A_HPP

#include "Base.hpp"


class A : private Base 
{
    public:
        int a;
        void foo(){
            a = 987;
            std::cout << "hi\n";
        };

};


#endif