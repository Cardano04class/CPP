#pragma once

#include <iostream>
#include "AForm.hpp"
#include "cstdlib"
#include "ctime"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const  RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const  RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};