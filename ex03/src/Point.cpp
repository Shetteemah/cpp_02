#include "../include/Fixed.hpp"
#include "../include/Point.hpp"


Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) {}

Point::~Point() {}

Point &Point::operator=(Point const &rhs) {
    // Check for self-assignment
    if (this == &rhs) {
        return *this;
    }

    // Copy values
    // Since _x and _y are const, we can't change their values directly.
    // Instead, we create a new Point object and swap it with *this.
    Point temp(rhs);
    std::swap(_x, temp._x);
    std::swap(_y, temp._y);
    return *this;
}

Fixed const Point::getX() const {
    return _x;
}

Fixed const Point::getY() const {
    return _y;
}



// public:
//     Fixed();
//     Fixed(Fixed const &fixed);
//     Fixed &operator=(Fixed const &fixed); // Mark the assignment operator as const
//     // ...
// private:
//     int _value;