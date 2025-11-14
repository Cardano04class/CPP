#pragma once 

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern
{
    private:
        typedef AForm* (Intern::*FormCreator)(const std::string&);
        FormCreator funcAP[3];
        AForm* createShrubberyForm(const std::string& target);
        AForm* createRobotomyForm(const std::string& target);
        AForm* createPresidentialForm(const std::string& target);
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(const std::string &formName, const std::string &target);

};