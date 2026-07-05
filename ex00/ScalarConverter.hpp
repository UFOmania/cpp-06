#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <errno.h>
#include <climits>
#include <sstream>



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
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		
	public:
        static void convert(const char * str);
};


#endif