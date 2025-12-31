#ifndef FIXED_HPP
    #define FIXED_HPP

#include <iostream>
#include <string>
#include <stdint.h>

class Fixed
{
    public:
        Fixed();
        Fixed( Fixed const & );
        ~Fixed();

        Fixed & operator=( Fixed const & );

        int getRawBits( void ) const;
        void setRawBits ( int const );

    private:
        int _rawBits;
        static int _fractionalBits;
};

#endif