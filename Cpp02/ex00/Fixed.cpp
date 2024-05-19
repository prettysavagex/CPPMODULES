#include "Fixed.hpp"

Fixed::Fixed() : fixpnbr(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copyc)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copyc;
}

Fixed &Fixed::operator=(const Fixed& copyc)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copyc)
        this->fixpnbr = copyc.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixpnbr;
}

void Fixed::setRawBits(int const raw)
{
    this->fixpnbr = raw;
}