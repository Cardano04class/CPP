#include "FileReplace.hpp"

int main(int ac, char **av){
    if (ac != 4)
    {
        std::cerr << "<filename> <s1> <s2>" << std::endl;
        return 1;
    }
    FileReplace replacer(av[1], av[2], av[3]);
    if (!replacer.process())
        return 1;
    return 0;
}