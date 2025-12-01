#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(42);

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);

    std::deque<int> deq;
    deq.push_back(-1);
    deq.push_back(-5);
    deq.push_back(-10);

    std::cout << "===== Testing std::vector =====" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(vec, 999);
    }
    catch (std::exception &e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing std::list =====" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 200);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(lst, 123);
    }
    catch (std::exception &e)
    {
        std::cout << "List error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Testing std::deque =====" << std::endl;
    try
    {
        std::deque<int>::iterator it = easyfind(deq, -10);
        std::cout << "Found in deque: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(deq, 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Deque error: " << e.what() << std::endl << std::endl;
    }

    std::cout << "===== Testing const container =====" << std::endl;
    const std::vector<int> cvec = vec;

    try
    {
        std::vector<int>::const_iterator it = easyfind(cvec, 42);
        std::cout << "Found in const vector: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
