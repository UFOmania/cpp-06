#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
        typedef enum type_e {
            E_CHAR, E_INT, E_DOUBLE, E_FLOAT
        } type_t;

        static int parseInput(std::string const & input);
        static void CharHandler(char c);
        static void IntHandler(std::string const & input);
        static void doubleHandler(std::string const & input);
        static void floatHandler(std::string & input);

    public:
        ~ScalarConverter();
        ScalarConverter();
        ScalarConverter(ScalarConverter const & other);
        ScalarConverter &operator=(ScalarConverter const & other);

        static void convert(const char * str);
};


#endif