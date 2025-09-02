#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Constructor edge cases ===" << std::endl;
    try {
        Form tooHigh("TooHigh", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form tooLow("TooLow", 151, 50);
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrats and Forms ===" << std::endl;
    Bureaucrat bob("Bob", 100);
    Bureaucrat alice("Alice", 40);
    Bureaucrat charlie("Charlie", 50);

    Form contract("Contract", 50, 30);
    Form nda("NDA", 40, 30);
    Form topSecret("TopSecret", 1, 1);

    std::cout << "\n--- Initial state ---" << std::endl;
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;
    std::cout << charlie << std::endl;
    std::cout << contract << std::endl;
    std::cout << nda << std::endl;
    std::cout << topSecret << std::endl;

    std::cout << "\n=== Test: signing with too low grade ===" << std::endl;
    bob.signForm(contract);  

    std::cout << "\n=== Test: signing with exact grade ===" << std::endl;
    charlie.signForm(contract);

    std::cout << "\n=== Test: signing already signed form ===" << std::endl;
    charlie.signForm(contract);

    std::cout << "\n=== Test: high-rank bureaucrat ===" << std::endl;
    alice.signForm(nda);      
    alice.signForm(nda);      
    charlie.signForm(topSecret);
    Bureaucrat chief("Chief", 1);
    chief.signForm(topSecret);
    std::cout << "\n--- Final state of forms ---" << std::endl;
    std::cout << contract << std::endl;
    std::cout << nda << std::endl;
    std::cout << topSecret << std::endl;

    return 0;
}
