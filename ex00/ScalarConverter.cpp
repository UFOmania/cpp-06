#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &){}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &){return *this;}

int ScalarConverter::parseInput(std::string const & input)
{
	
	{
		std::string float_specails[] = { "-inff", "+inff", "nanf"};
		std::string double_specails[] = {"+inf", "-inf", "nan"};

		std::string normalizedInput;
		for(int i = 0; i < static_cast<int>(input.length()); ++i)
		{
			if (std::isupper(input[i]))
            	normalizedInput += static_cast<char>(std::tolower(input[i]));
			else
            	normalizedInput += input[i];
		}
		
		for (int i = 0; i < 3; i++)
		{
			if (float_specails[i] == normalizedInput)
				return E_FLOAT;
		}
		for (int i = 0; i < 3; i++)
		{
			if (double_specails[i] == normalizedInput)
				return E_DOUBLE;
		}
	}
	
	
    int inputLen = input.length();


    if (inputLen == 0)
        throw std::runtime_error("Invalid input");


    else if (inputLen == 1)
    {
        if (std::isspace(input[0]))
            throw std::runtime_error("Invalid input");

        if (std::isdigit(input[0]))
            return E_INT;
        return E_CHAR;

    }


    else
    {
        bool decimal = false;
        int idx = 0;
        if (input[0] == '-')
            idx++;
        for (; idx < inputLen; idx++)
        {
            if (!std::isdigit(input[idx]))
                break;
            decimal = true;
        }

        if (idx == inputLen)
            return E_INT;


        else if (input[idx] != '.')
            throw std::runtime_error("Invalid input");


        if (!decimal)
            throw std::runtime_error("Invalid input");


        bool fractional = false;
        idx++;
        for (; idx < static_cast<int>(input.length()); idx++)
        {
            if (!std::isdigit(input[idx]))
                break;
            fractional = true;
        }

        if (!fractional)
            throw std::runtime_error("Invalid input");


        if (idx == inputLen)
            return E_DOUBLE;
        
        else if (idx == inputLen - 1 && input[idx] == 'f')
            return E_FLOAT;

        else
            throw std::runtime_error("Invalid input");
    }
}

void ScalarConverter::CharHandler(char c)
{
    std::cout << "char: " << c << "\n";

    int i = static_cast<int>(c);
    std::cout << "int: " << i << "\n";

    float f = static_cast<float>(c);
    std::cout << "float: " << f << ".0f" << "\n";

    double d = static_cast<double>(c);
    std::cout << "double: " << d << ".0" << "\n";

}
void ScalarConverter::IntHandler(std::string const & input)
{
    std::cout << std::fixed << std::setprecision(1);
    
        std::stringstream ss(input);
        int buff;
        if (!(ss >> buff))
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return ;
        }

        if (buff > 127 || buff < -128)
            std::cout << "char: impossible\n";
        else
        {
            char c = static_cast<char>(buff);
            if (!std::isprint(c) || std::isspace(c))
                std::cout << "char: Non displayable\n";
            else
                std::cout << "char: " << c << "\n";
        }
            

        
        int i = static_cast<int>(buff);
        std::cout << "int: " << i << "\n";
    

        
        float f = static_cast<float>(buff);
        std::cout << "float: " << f << "f\n";

        double d = static_cast<double>(buff);
        std::cout << "double: " << d << "\n";
}

void ScalarConverter::floatHandler(std::string & input)
{
    if (!input.empty())
        input.erase(input.size() - 1);


    int dot_pos = input.find('.');
    int precision = input.length() - 1 - dot_pos;


    std::cout << std::fixed << std::setprecision(precision);
    

    std::stringstream ss(input);
    float buff;

    if (!(ss >> buff))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return ;
    }

    if (buff > 127.0f || buff < -128.0f)
            std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(buff);
        if (!std::isprint(c) || std::isspace(c))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << c << "\n";
    }
    
    if (buff > static_cast<float>(INT_MAX) || buff < static_cast<float>(INT_MAX))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(buff) << "\n";
    std::cout << "float: " << buff << "f\n";
    std::cout << "double: " << strtod(input.c_str(), NULL) << "\n";
}

void ScalarConverter::doubleHandler(std::string const & input)
{
    int dot_pos = input.find('.');
    int precision = input.length() - 1 - dot_pos;


    std::cout << std::fixed << std::setprecision(precision);
    
    std::stringstream ss(input);
    double buff;
    if (!(ss >> buff))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return ;
    }

    if (buff > 127.0 || buff < -128.0)
            std::cout << "char: impossible\n";
    else
    {
        char c = static_cast<char>(buff);
        if (!std::isprint(c) || std::isspace(c))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << c << "\n";
    }
    
    if (buff > INT_MAX || buff < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(buff) << "\n";
    
    std::cout << "float: " << static_cast<float>(buff) << "f\n";
    std::cout << "double: " << buff << "\n";
}

void ScalarConverter::convert(char const * str)
{
    try
    {
        std::string input(str);
        
        int type = parseInput(input);
        switch (type)
        {
            case E_CHAR:
                CharHandler(input[0]);
                break;
            case E_INT:
                IntHandler(input);
                break;
            case E_FLOAT:
                floatHandler(input);
                break;
            case E_DOUBLE:
                doubleHandler(input);
                break;
            
        }
        
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}