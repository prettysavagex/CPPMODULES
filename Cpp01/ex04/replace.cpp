#include "replace.hpp"
#include <fstream>

Replacer::Replacer()
{

}

Replacer::Replacer(std::string filename) : in_file(filename)
{
    this->out_file = this->in_file + ".replace";
}

Replacer::~Replacer()
{

}

void    Replacer::replacer(std::string s1, std::string s2)
{
    std::ifstream inp(this->in_file);
    if (inp.is_open())
    {
        std::string input;
        if (std::getline(inp, input, '\0'))
        {
            std::ofstream outp(this->out_file);
            size_t size = input.find(s1);
            while(size != std::string::npos)
            {
                input.erase(size, s1.length());
                input.insert(size, s2);
                size = input.find(s1);
            }
            outp << input;
            outp.close();
        }
        else
            std::cout << "The file is empty!" << std::endl;
        inp.close();
    }
    else
    {
        std::cout << "The file cannot be opened!" << std::endl;
        exit(EXIT_FAILURE);
    }
}