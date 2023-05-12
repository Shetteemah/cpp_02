#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(int const value) : _value(value << _fractionalBits) {}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _fractionalBits))) {}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    if (this != &rhs)
	{
        _value = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits() const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    return _value >> _fractionalBits;
}

Fixed::~Fixed() {}

bool Fixed::operator>(Fixed const & rhs) const
{
    return _value > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const
{
    return _value < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const
{
    return _value >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const
{
    return _value <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const
{
    return _value == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const
{
    return _value != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
    Fixed res;
    res.setRawBits(_value + rhs.getRawBits());
    return res;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
    Fixed res;
    res.setRawBits(_value - rhs.getRawBits());
    return res;
}

