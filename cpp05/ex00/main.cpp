#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("namir", 42);
    std::cout << a << std::endl;
    try {
        Bureaucrat b4("Diana", 2);
        b4.incrementGrade(); // should succeed, now 1
        b4.incrementGrade(); // should throw GradeTooHighException
    } 
    catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

std::cout << "------------------------" << std::endl;

    try {
        Bureaucrat b5("Eve", 149);
        b5.decrementGrade(); // should succeed, now 150
        b5.decrementGrade(); // should throw GradeTooLowException
    } 
    catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}