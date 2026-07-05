#ifndef BASE_HPP
#define BASE_HPP


class Base 
{
    public:
        virtual ~Base();
        Base();
        Base(const Base &);
        Base &operator=(const Base &);
};


#endif