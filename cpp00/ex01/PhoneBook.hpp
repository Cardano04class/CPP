#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook{
private:
    Contact contacts[8];
    int index;
    int count;
public:
    PhoneBook();
    void addContact();
    void searchContacts() const;

};

#endif