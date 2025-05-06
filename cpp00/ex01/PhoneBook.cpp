#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : index(0), count (0){} 

void PhoneBook::addContact()
{
    contacts[index % 8].getInfo();
    if (count < 8)
        count++;
    index++;
}

void PhoneBook::searchContacts() const
{
    if (count == 0)
    {
        std::cout << "No Contacts in PhoneBook" << std::endl;
        return;
    }
    std::cout   << "|" << std::setw(10) << "Index"
                << "|" << std::setw(10) << "FirstName"
                << "|" << std::setw(10) << "LastName"
                << "|" << std::setw(10) << "NickName" 
                << "|" << std::endl;
    for(int i = 0; i < count; i++)
        contacts[i].displayContacts(i);
    std::cout << "Enter Index: ";
    
    std::string input;
    getline(std::cin, input);
    if (input.length() == 1 && isdigit(input[0]))
    {
        int i = input[0] - '0';
        if (i >= 0 && i < count)
            contacts[i].displayFull();
        else
            std::cout << "Invalid Index" << std::endl;
    }
    else
        std::cout << "Invalid Input" << std::endl;
}
