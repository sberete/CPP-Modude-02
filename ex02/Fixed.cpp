#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : _rawBits(0){}

Fixed::Fixed( int const nb )
{
    _rawBits =  nb << _fractionalBits;
}
        
Fixed::Fixed( Fixed const & src )
{
    *this = src;
}

Fixed::Fixed( float const nb )
{
    _rawBits = roundf(nb * (1 << _fractionalBits));
}

Fixed::~Fixed(){}

float Fixed::toFloat() const
{
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _rawBits >> _fractionalBits;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
    this->_rawBits = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    return this->_rawBits;
}

void Fixed::setRawBits( int const raw )
{
    _rawBits = raw;
}

bool Fixed::operator>( Fixed const & rhs ) const 
{
    return this->_rawBits > rhs.getRawBits();
}

bool Fixed::operator<( Fixed const & rhs ) const 
{
    return this->_rawBits < rhs.getRawBits();
}

bool Fixed::operator>=( Fixed const & rhs ) const 
{
    return this->_rawBits >= rhs.getRawBits();
}

bool Fixed::operator<=( Fixed const & rhs ) const 
{
    return this->_rawBits <= rhs.getRawBits();
}

bool Fixed::operator==( Fixed const & rhs ) const 
{
    return this->_rawBits == rhs.getRawBits();
}

bool Fixed::operator!=( Fixed const & rhs ) const 
{
    return this->_rawBits != rhs.getRawBits();
}

Fixed Fixed::operator+( Fixed const & rhs ) const 
{
    Fixed result;
    result.setRawBits(this->_rawBits + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-( Fixed const & rhs ) const 
{
    Fixed result;
    result.setRawBits(this->_rawBits - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*( Fixed const & rhs ) const 
{
    Fixed result;
    long tmp = (long)this->_rawBits * (long)rhs.getRawBits();
    result.setRawBits(tmp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/( Fixed const & rhs ) const 
{
    Fixed result;
    long tmp = ((long)this->_rawBits << _fractionalBits);
    result.setRawBits(tmp / rhs.getRawBits());
    return result;
}

Fixed & Fixed::operator++() 
{
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed result(*this);
    this->_rawBits++;
    return result;
}

Fixed & Fixed::operator--() 
{
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--( int ) 
{
    Fixed result(*this);
    this->_rawBits--;
    return result;   
}

Fixed & Fixed::min( Fixed & lhs, Fixed & rhs )
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed const & Fixed::min( Fixed const & lhs, Fixed const & rhs ) 
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed & Fixed::max( Fixed &lhs, Fixed & rhs ) 
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}

Fixed const & Fixed::max( Fixed const & lhs, Fixed const & rhs) 
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    return rhs;
}


std::ostream & operator<<( std::ostream & o, Fixed const & rhs )
{
    o << rhs.toFloat();
    return o;
}

int Fixed::_fractionalBits = 8;