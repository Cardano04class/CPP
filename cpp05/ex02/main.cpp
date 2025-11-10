#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat alice("Alice", 40);
    Bureaucrat bob("Bob", 100);

    RobotomyRequestForm robo("TargetX");

    bob.signForm(robo);
    bob.executeForm(robo);

    alice.signForm(robo);
    alice.executeForm(robo);

    return 0;
}
