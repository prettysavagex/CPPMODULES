#pragma once
#include <iostream>

class Replacer
{
    private:
        std::string in_file;
        std::string out_file;

    public:
        void replacer(std::string s1, std::string s2);
        Replacer();
        Replacer(std::string filename);
        ~Replacer();
};