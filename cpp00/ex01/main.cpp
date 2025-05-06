#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    while (1)
    {
        std::cout << "Welcome to the PhoneBook: ADD, SEARCH OR EXIT: ";
        if (!getline(std::cin, command))
        {
            std::cout << std::endl;
            break;
        }
        if (command == "ADD")
            phoneBook.addContact();
        else if(command == "SEARCH")
        {
            phoneBook.searchContacts();
        }
        else if (command == "EXIT")
            break;
        else if (command == "")
            continue;
        else
            std::cout << "Invalid command." << std::endl;
    }
}
