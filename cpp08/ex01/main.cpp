#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    // ===== Basic Tests =====
    std::cout << "=== Basic Tests ===" << std::endl;

    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan()  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // ===== Exception: adding beyond capacity =====
    std::cout << "\n=== Capacity Exception Test ===" << std::endl;

    try
    {
        Span sp(2);
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);    // should throw
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // ===== Exception: not enough numbers =====
    std::cout << "\n=== Not Enough Numbers Test ===" << std::endl;

    try
    {
        Span sp(10);
        sp.addNumber(5);
        std::cout << sp.shortestSpan() << std::endl; // should throw
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // ===== Range Insertion Test (10,000 numbers) =====
    std::cout << "\n=== Range Insertion (10,000 numbers) ===" << std::endl;

    try
    {
        Span big(10000);
        std::vector<int> buffer;
        buffer.reserve(10000);

        for (int i = 0; i < 10000; ++i)
            buffer.push_back(rand());

        big.addRange(buffer.begin(), buffer.end());

        std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << big.longestSpan()  << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // ===== Small visible test for correctness =====
    std::cout << "\n=== Small Visible Test ===" << std::endl;

    try
    {
        Span sp(6);
        sp.addNumber(1);
        sp.addNumber(100);
        sp.addNumber(50);
        sp.addNumber(51);
        sp.addNumber(52);
        sp.addNumber(53);

        std::cout << "Numbers: {1, 100, 50, 51, 52, 53}" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // should be 1
        std::cout << "Longest span:  " << sp.longestSpan()  << std::endl; // should be 99
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
