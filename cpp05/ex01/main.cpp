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
    bob.signForm(contract);   // should fail

    std::cout << "\n=== Test: signing with exact grade ===" << std::endl;
    charlie.signForm(contract); // should succeed (grade == required)

    std::cout << "\n=== Test: signing already signed form ===" << std::endl;
    charlie.signForm(contract); // should fail, already signed

    std::cout << "\n=== Test: high-rank bureaucrat ===" << std::endl;
    alice.signForm(nda);      // should succeed
    alice.signForm(nda);      // already signed → should show already signed (via exception or custom message)
    charlie.signForm(topSecret); // grade too low → should fail
    Bureaucrat chief("Chief", 1);
    chief.signForm(topSecret); // should succeed

    std::cout << "\n--- Final state of forms ---" << std::endl;
    std::cout << contract << std::endl;
    std::cout << nda << std::endl;
    std::cout << topSecret << std::endl;

    return 0;
}
