#include "../include/Fixed.hpp"

Fixed::~Fixed() {}

// Rest of the code remains the same
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(int const value) : _value(value << _fractionalBits) {}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _fractionalBits))) {}

Fixed::Fixed(Fixed const & src)
{
    _value = src._value;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    if (this != &rhs)
    {
        _value = rhs.getRawBits();
    }
    return *this;
}

Fixed & Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed Fixed::operator*(Fixed const& rhs) const
{
    Fixed result;
    result.setRawBits((_value * rhs.getRawBits()) >> _fractionalBits);
    return result;
}

std::ostream& operator<<(std::ostream& o, Fixed const& i)
{
    o << i.toFloat();
    return o;
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
