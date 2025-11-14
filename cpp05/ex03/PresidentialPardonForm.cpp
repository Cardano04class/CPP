#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5, target)
{
    std::cout << "PresidentialPardonForm constructor for target" << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "PresidentialPardonForm Copy constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void)other;
    std::cout << "PresidentialPardonForm Copy Assignment Operator" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(!getIsSigned())
        throw FormNotSignedException();
    if(executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

