#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <string>

class Contact{
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;
    
public:
    void getInfo();
    void displayContacts(int index) const;
    void displayFull() const;
};

#endif