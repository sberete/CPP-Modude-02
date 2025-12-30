#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point( float const x, float const y ) : _x(x), _y(y) {}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY()) {}

Point & Point::operator=( Point const & rhs ){}

Point::~Point(){}

Fixed Point::getX()const
{
    return this->_x;
}
Fixed Point::getY()const
{
    return this->_y;
}
