#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 2);
        alice.incrementGrade(); // → 1
        alice.incrementGrade(); // → exception
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "--------------------------" << std::endl;

    try {
        Bureaucrat bob("Bob", 149);
        bob.decrementGrade(); // → 150
        bob.decrementGrade(); // → exception
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
