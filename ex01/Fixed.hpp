#ifndef FIXED_HPP
    #define FIXED_HPP

#include <iostream>
#include <string>
#include <stdint.h>

class Fixed
{
    public:
        Fixed();
        Fixed( int const );
        Fixed( float const );
        Fixed( Fixed const & );
        ~Fixed();

        Fixed & operator=( Fixed const & );

        float toFloat( void ) const;
        int toInt( void ) const;

        int getRawBits( void ) const;
        void setRawBits ( int const );

    private:
        int _rawBits;
        static int _fractionalBits;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif