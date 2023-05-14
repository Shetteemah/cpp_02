#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string.h>
#include <cmath>
#include "./Fixed.hpp"

class Fixed;

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(float const x, float const y);
        Point(Point const &src);
        ~Point();

        Point &operator=(Point const &rhs);

        const Fixed getX(void) const;
        const Fixed getY(void) const;

};

#endif
