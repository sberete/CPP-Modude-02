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

        bool operator>( Fixed const & ) const;
        bool operator<( Fixed const & ) const;
        bool operator>=( Fixed const & ) const;
        bool operator<=( Fixed const & ) const;
        bool operator==( Fixed const & ) const;
        bool operator!=( Fixed const & ) const;

        Fixed operator+( Fixed const & ) const;
        Fixed operator-( Fixed const & ) const;
        Fixed operator*( Fixed const & ) const;
        Fixed operator/( Fixed const & ) const;

        Fixed & operator++();
        Fixed operator++( int );
        Fixed & operator--();
        Fixed operator--( int );

        static Fixed & min( Fixed &, Fixed & );
        static Fixed const & min( Fixed const &, Fixed const & );
        static Fixed & max( Fixed &, Fixed & );
        static Fixed const & max( Fixed const &, Fixed const & );

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