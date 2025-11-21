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

void ScalarConverter::convert(const std::string &literal)
{

}