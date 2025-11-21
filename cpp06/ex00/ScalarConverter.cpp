#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    return *this;
}

static bool isChar(const std::string &literal)
{
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return true;
    return false;
}

static bool isInt(const std::string &literal)
{
    if (literal.empty())
        return false;
    size_t i = 0;
    if(literal[0] == '+' || literal[0] == '-')
        i++;
    for(; i < literal.length(); ++i)
    {
        if (!isdigit(literal[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string &literal)
{
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;
    std::string sub_f = literal.substr(0, literal.length() -1);
    bool has_dot = false;
    size_t i = 0;
    for (; i < sub_f.length(); ++i)
    {
        if(sub_f[i] == '.' && !has_dot)
            has_dot = true;
        else if (!isdigit(sub_f[i]))
            return false;
    }
    return has_dot;
}

static bool isDouble(const std::string &literal)
{
    if (literal.empty())
        return false;
    bool hasDot = false;
    size_t i = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++; 
    for(; i < literal.length(); ++i)
    {
        if (literal[i] == '.' && !hasDot)
            hasDot = true;
        else if (!isdigit(literal[i]))
            return false;
    }
    return hasDot;
}

static bool isPseudoLiteral(const std::string &literal)
{
    return  (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

static void convertFromChar(char c)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void convertFromInt(int i)
{
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else    
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void convertFromFloat(float f)
{
    if (isnan(f) || isinf(f))
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
    }
    else
    {
        if (f >= 32 && f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: Impossible" << std::endl;
        else    
            std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(f);
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << std::endl;
}

static void convertFromDouble(double d)
{
    if (isnan(d) || isinf(d))
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
    }
    else
    {
        if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (d > std::numeric_limits<int>::max()  || d < std::numeric_limits<int>::min())
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    std::cout << "float: " << static_cast<float>(d);
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

static void convertFromPseudoLiteral(const std::string &literal)
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{

}