#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 100);
        Form contract("Contract", 50, 30);

        std::cout << "Trying to sign the form..." << std::endl;
        contract.beSigned(bob);  // Should throw, grade too low
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Now try with a high-rank bureaucrat ===" << std::endl;

    try {
        Bureaucrat alice("Alice", 20);
        Form nda("NDA", 50, 30);

        nda.beSigned(alice);  // Should succeed

        std::cout << "Form '" << nda.getName() << "' is signed: "
                  << std::boolalpha << nda.getIsSigned() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
