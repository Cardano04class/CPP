#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

int all_printable(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!isprint(str[i]))
            return 0;
    }
    return 1;
}

int all_digits(std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

std::string checklength (std::string str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (i > 9)
        {
            str.resize(9);
            str.append(".");
        }
    }
    return str;
}

void Contact::getInfo()
{
    while (1)
    {
        std::cout << "FirstName: "; 
        if(!getline(std::cin, FirstName))
        {
            std::cout << "Error!" << std::endl;
            exit(1);
        }
        if(!FirstName.empty() && all_printable(FirstName))
            break;
    }
    while(1)
    {
        std::cout << "LastName: "; 
        if(!getline(std::cin, LastName))
        {
            std::cout << "Error!" << std::endl;
            exit(1);
        }
        if(!LastName.empty() && all_printable(LastName))
            break;
    }
    while(1)
    {
        std::cout << "NickName: "; 
        if(!getline(std::cin, NickName))
        {
            std::cout << "Error!" << std::endl;
            exit(1);
        }
        if(!NickName.empty() && all_printable(NickName))
            break;
    }
    while(1)
    {
        std::cout << "PhoneNumber: "; 
        if(!getline(std::cin, PhoneNumber))
        {
            std::cout << "Error!" << std::endl;
            exit(1);
        }
        if(!PhoneNumber.empty() && all_digits(PhoneNumber))
            break;
    }
    while(1)
    {
        std::cout << "DarkestSecret: ";
        if(!getline(std::cin, DarkestSecret))
        {
            std::cout << "Error!" << std::endl;
            exit(1);
        }
        if(!DarkestSecret.empty() && all_printable(DarkestSecret))
            break;
    }
}

void Contact::displayContacts(int index) const
{

    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << checklength(FirstName)
              << "|" << std::setw(10) << checklength(LastName)
              << "|" << std::setw(10) << checklength(NickName) 
              << "|" << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "FirstName: " << FirstName << std::endl;
    std::cout << "LastName: " << LastName << std::endl;
    std::cout << "NickName: " << NickName << std::endl;
    std::cout << "PhoneNumber: " << PhoneNumber << std::endl;
    std::cout << "DarkestSecret: " << DarkestSecret << std::endl;
}
