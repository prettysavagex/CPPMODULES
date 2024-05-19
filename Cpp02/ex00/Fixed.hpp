#pragma once
#include <iostream>

class Fixed
{
    private:
        int fixpnbr = 0;
        static const int bit = 8;

    public:
        Fixed();
        Fixed(const Fixed& copyc);
        ~Fixed();
        Fixed& operator=(const Fixed& copyc);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
