#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixpnbr(0) 
{

}

Fixed::Fixed(const int fixpnbr) : fixpnbr(fixpnbr << bit) 
{

}

Fixed::Fixed(const float fixpnbr) : fixpnbr(int(roundf(fixpnbr * (1 << bit)))) 
{

}

Fixed &Fixed::operator=(const Fixed& copyc)
{

    if (this != &copyc)
        this->fixpnbr = copyc.fixpnbr;
    return *this;
}

Fixed::Fixed(const Fixed& copyc)
{
    *this = copyc;
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
    return this->fixpnbr;
}

void Fixed::setRawBits(int const raw)
{
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

bool Fixed::operator==(const Fixed &copyc) const
{
    return this->fixpnbr == copyc.fixpnbr;
}

bool Fixed::operator!=(const Fixed &copyc) const
{
    return this->fixpnbr != copyc.fixpnbr;
}

bool Fixed::operator>(const Fixed &copyc) const
{
    return this->fixpnbr > copyc.fixpnbr;
}

bool Fixed::operator<(const Fixed &copyc) const
{
    return this->fixpnbr < copyc.fixpnbr;
}

bool Fixed::operator>=(const Fixed &copyc) const
{
    return this->fixpnbr >= copyc.fixpnbr;
}

bool Fixed::operator<=(const Fixed &copyc) const
{
    return this->fixpnbr <= copyc.fixpnbr;
}

Fixed Fixed::operator+(const Fixed &copyc) const
{
    Fixed result;
    result.setRawBits(this->fixpnbr + copyc.fixpnbr);
    return result;
}

Fixed Fixed::operator-(const Fixed &copyc) const
{
    Fixed result;
    result.setRawBits(this->fixpnbr - copyc.fixpnbr);
    return result;
}

Fixed Fixed::operator*(const Fixed &copyc) const
{
    Fixed result;
    result.setRawBits(((this->fixpnbr) * copyc.fixpnbr) >> bit);
    return result;
}

Fixed Fixed::operator/(const Fixed &copyc) const
{
    Fixed result;
    result.setRawBits(((this->fixpnbr) << bit) / copyc.fixpnbr);
    return result;
}

Fixed &Fixed::operator++()
{
    ++this->fixpnbr;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed &Fixed::operator--()
{
    --this->fixpnbr;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
