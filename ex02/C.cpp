#include "C.hpp"

C::~C(){}
C::C(){}
C::C(const C &){}
C &C::operator=(const C &){return *this;}

void C::sayHi()
{
    std::cout << "Hi prismo!" << std::endl;
}