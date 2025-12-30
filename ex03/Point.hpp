#ifndef POINT-HPP
    #define POINT-HPP

#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point( float const x, float const y);
    private:
        Fixed const _x;      
        Fixed const _y;      
};

#endif