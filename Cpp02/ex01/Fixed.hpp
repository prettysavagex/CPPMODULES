#pragma once
#include <iostream>

class Fixed
{
	private:
		int fixpnbr;
		static const int bit = 8;

	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
        Fixed(const Fixed& copyc);
        Fixed& operator=(const Fixed& copyc);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);