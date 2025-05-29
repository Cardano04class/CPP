#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
    if (grade >= 1 && grade <= 150)
    {
        this->name = name;
        this->grade = grade;
        std::cout << "Parametrized Constructor for " << name << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor" << std::endl;
}