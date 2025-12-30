#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;

}
        
Fixed::Fixed(Fixed const & rhs)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed & Fixed::operator=(Fixed const & rhs) // right hand side
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

int Fixed::_fractional_bits = 8;