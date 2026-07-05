#include "B.hpp"

B::~B(){}
B::B(){}
B::B(const B &){}
B &B::operator=(const B &){return *this;}

void B::toUpper(std::string &str)
{
    for(size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
}