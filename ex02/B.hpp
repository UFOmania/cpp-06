#ifndef B_HPP
#define B_HPP

#include "Base.hpp"
#include <string>

class B : public Base 
{
    public:
        ~B();
        B();
        B(const B &);
        B &operator=(const B &);
        void toUpper(std::string &);
};


#endif