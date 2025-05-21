#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating Animals ===" << std::endl;

    // Animal a;

    Dog dog;
    Cat cat;

    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    dog.makeSound();  
    cat.makeSound();  

    std::cout << "\n=== Testing getType() ===" << std::endl;
    std::cout << "Dog type: " << dog.getType() << std::endl;
    std::cout << "Cat type: " << cat.getType() << std::endl;

    std::cout << "\n=== Cleaning up ===" << std::endl;
    
    return 0;
}
