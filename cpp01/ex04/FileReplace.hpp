#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <iostream>
#include <fstream>

class FileReplace{
    private:
        std::string filename;
        std::string s1;
        std::string s2;
    public:
        FileReplace(const std::string& filename, const std::string& s1, const std::string& s2);
        bool process();
};
#endif