#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(float const x, float const y);
    Point(Point const& src);
    ~Point();

    Point& operator=(Point const& rhs);

    Fixed const getX() const;
    Fixed const getY() const;

private:
    Fixed const _x;
    Fixed const _y;
};

#endif
