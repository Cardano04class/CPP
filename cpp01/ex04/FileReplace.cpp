#include "FileReplace.hpp"

FileReplace::FileReplace(const std::string& filename, const std::string& s1, const std::string& s2) : filename(filename), s1(s1), s2(s2){}

bool FileReplace::process(){
    std::ifstream inFile(filename);
    if(!inFile)
    {
        std::cerr << "Error: cannot open input file!" << std::endl;
        return false;
    } 

    std::ofstream outFile(filename + ".replace");
    if(!outFile)
    {
        std::cerr << "Error: cannot open outnput file!" << std::endl;
        return false;
    }

    std::string line;

    while(getline(inFile, line))
    {
        size_t pos = 0;
        while((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outFile << line << std::endl;
    }
    
    inFile.close();
    outFile.close();
    return true;
}