#include <iostream>

int main()
{
    std::string obj = "HI THIS IS BRAIN";
    std::string *stringPTR = &obj;
    std::string &stringREF = obj;

    std::cout << &obj << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << obj << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}