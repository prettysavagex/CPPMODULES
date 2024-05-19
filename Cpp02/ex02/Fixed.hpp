#pragma once
#include <iostream>

class Fixed
{
	private:
		int fixpnbr;
		static const int bit = 8;
	public:
		Fixed();
		Fixed(const int fixpnbr);
		Fixed(const float fixpnbr);
		Fixed(const Fixed& copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

    	bool operator==(const Fixed &copy) const;
    	bool operator!=(const Fixed &copy) const;
		bool operator>(const Fixed &copy) const;
    	bool operator<(const Fixed &copy) const;
    	bool operator>=(const Fixed &copy) const;
    	bool operator<=(const Fixed &copy) const;

		Fixed operator+(const Fixed &copy) const;
    	Fixed operator-(const Fixed &copy) const;
    	Fixed operator*(const Fixed &copy) const;
    	Fixed operator/(const Fixed &copy) const;

		Fixed &operator++();
    	Fixed operator++(int);
    	Fixed &operator--();
    	Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
    	static const Fixed &min(const Fixed &a, const Fixed &b);
    	static Fixed &max(Fixed &a, Fixed &b);
    	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);