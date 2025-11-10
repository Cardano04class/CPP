#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Constructor edge cases ===" << std::endl;
    try
    {
        ShrubberyCreationForm f1("Home");
        RobotomyRequestForm f2("TargetX");
        PresidentialPardonForm f3("President");
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrats and Forms ===" << std::endl;
    Bureaucrat bob("Bob", 150);       // Low grade
    Bureaucrat charlie("Charlie", 50); // Medium grade
    Bureaucrat alice("Alice", 1);     // High grade

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("TargetX");
    PresidentialPardonForm pardon("Zaphod");

    std::cout << "--- Initial state ---" << std::endl;
    std::cout << bob << std::endl;
    std::cout << charlie << std::endl;
    std::cout << alice << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n=== Signing Tests ===" << std::endl;
    bob.signForm(shrub);     // Too low
    charlie.signForm(shrub); // Should succeed
    charlie.signForm(robo);  // Too low
    alice.signForm(robo);    // Should succeed
    bob.signForm(pardon);    // Too low
    alice.signForm(pardon);  // Should succeed

    std::cout << "\n=== Execute Tests ===" << std::endl;
    bob.executeForm(shrub);     // Too low
    charlie.executeForm(shrub); // Should succeed, create file
    charlie.executeForm(robo);  // Too low
    alice.executeForm(robo);    // Should succeed, random success/fail
    alice.executeForm(pardon);  // Should succeed, print message

    std::cout << "\n--- Final state ---" << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    return 0;
}
