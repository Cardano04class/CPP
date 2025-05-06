#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>

class Contact{
private:
    std::string FirstName;
    std::string LastName;
    std::string Address;
    int Number;
    
public:
    void getInfo();
    void displayInfo(int index) const;
    void displayFull() const;
};

#endif