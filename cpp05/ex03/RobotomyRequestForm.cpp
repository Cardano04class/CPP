#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45, target)
{
    std::cout << "RobotomyRequestForm constructor for target" << target << std::endl;
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void) other;
    std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "* Drilling noises... *" << std::endl;
    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else 
        std::cout << "robotomy failed on " << getTarget() << std::endl;
}

