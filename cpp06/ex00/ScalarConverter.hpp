#pragma once

#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter &operator=(const ScalarConverter&);
        ~ScalarConverter();

    public:

        static void convert(const std::string &literal);
};