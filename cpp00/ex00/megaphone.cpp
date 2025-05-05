#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else 
    {
        for (int i = 1; i < ac; i++)
        {
            std::string str = av[i];
            for(char &c : str)
            {
                std::cout << (char)std::toupper(c);
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}