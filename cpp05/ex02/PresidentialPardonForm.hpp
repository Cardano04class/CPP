#pragma once

#include "AForm.hpp"
#include "iostream"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const  PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const  PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;

};