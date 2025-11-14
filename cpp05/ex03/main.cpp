#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "=== Intern Form Creation Tests ===" << std::endl;
    Intern intern;

    AForm* f1 = intern.makeForm("Shrubbery request", "Home");
    AForm* f2 = intern.makeForm("Robotomy request", "TargetX");
    AForm* f3 = intern.makeForm("Presidential pardon", "Zaphod");
    AForm* f4 = intern.makeForm("Unknown form", "Nobody");

    std::cout << "\n=== Bureaucrats ===" << std::endl;
    Bureaucrat bob("Bob", 120);
    Bureaucrat alice("Alice", 1);
    Bureaucrat charlie("Charlie", 50);

    std::cout << "\n=== Signing Tests ===" << std::endl;

    if (f1)
        bob.signForm(*f1);
    if (f2)
        charlie.signForm(*f2);
    if (f3)
        alice.signForm(*f3);

    std::cout << "\n=== Execution Tests ===" << std::endl;

    if (f1)
        bob.executeForm(*f1);
    if (f1)
        charlie.executeForm(*f1);

    if (f2)
        charlie.executeForm(*f2);
    if (f2)
        alice.executeForm(*f2);

    if (f3)
        charlie.executeForm(*f3);
    if (f3)
        alice.executeForm(*f3);

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}
