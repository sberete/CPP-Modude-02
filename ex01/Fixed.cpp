#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const nb )
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits =  nb << _fractional_bits;
}
        
Fixed::Fixed( Fixed const & rhs )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::Fixed( float const nb )
{
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(nb * (1 << _fractional_bits));
}

float Fixed::toFloat() const
{
    return (float)_rawBits / (1 << _fractional_bits);
}

int Fixed::toInt() const
{
    return _rawBits >> _fractional_bits;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits()const
{
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
    o << rhs.toFloat();
    return o;
}

int Fixed::_fractional_bits = 8;