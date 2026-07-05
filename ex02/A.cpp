#include "A.hpp"

A::~A(){}
A::A(){}
A::A(const A &){}
A &A::operator=(const A &){return *this;}


int A::addTwo(int a, int b){
    return a + b;
}
