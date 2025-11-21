// main.cpp
#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [literal]" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    std::cout << "\n=== Converting: \"" << input << "\" ===\n" << std::endl;

    ScalarConverter::convert(input);

    return 0;
}