#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::getInfo()
{
    while (1)
    {
        std::cout << "FirstName: "; getline(std::cin, FirstName);
        if(!FirstName.empty())
            break;
    }
    while(1)
    {
        std::cout << "LastName: "; getline(std::cin, LastName);
        if(!LastName.empty())
            break;
    }
    while(1)
    {
        std::cout << "NickName: "; getline(std::cin, NickName);
        if(!NickName.empty())
            break;
    }
    while(1)
    {
        std::cout << "PhoneNumber: "; getline(std::cin, PhoneNumber);
        if(!PhoneNumber.empty())
            break;
    }
    while(1)
    {
        std::cout << "DarkestSecret: "; getline(std::cin, DarkestSecret);
        if(!DarkestSecret.empty())
            break;
    }
}

void Contact::displayContacts(int index) const
{
    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << FirstName
              << "|" << std::setw(10) << LastName
              << "|" << std::setw(10) << NickName 
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
