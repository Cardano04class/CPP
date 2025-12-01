#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    std::cout << "===== Testing with std::vector =====" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    
    try
    {
        if(easyfind(vec, 30))
            std::cout << "Value 30 found in vector " << std::endl;
        else
            throw std::runtime_error("Value Not found"); 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        if (easyfind(vec, 550))
            std::cout << "Value 550 found in vector " << std::endl;
        else
            throw std::runtime_error("Value Not found");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "===== Testing with std::list =====" << std::endl;
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    try
    {
        if(easyfind(lst, 20))
            std::cout << "20 found in list" << std::endl;
        else
            throw std::runtime_error("Value Not found");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try
    {
        if(easyfind(lst, 100))
            std::cout << "100 found in list" << std::endl;
        else
            throw std::runtime_error("Value Not found");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}