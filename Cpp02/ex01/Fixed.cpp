#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixpnbr(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixpnbr) : fixpnbr(fixpnbr << bit)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixpnbr) : fixpnbr((int)(roundf(fixpnbr * (1 << bit))))
{
    std::cout << "Float constructor called" << std::endl;
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
        this->fixpnbr = copyc.fixpnbr;
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
    std::cout << "setRawBits member function called" << std::endl;
    this->fixpnbr = raw;
}

float Fixed::toFloat(void) const 
{
    return (float)(this->fixpnbr) / (1 << bit);
}

int Fixed::toInt(void) const
{
    return this->fixpnbr >> bit;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}