#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(int const _value) : _value(_value << _bits) {}

Fixed::Fixed(float const _value) : _value(roundf(_value * (1 << _bits))) {}

Fixed::Fixed(Fixed const &fixed) : _value(fixed.getRawBits()) {}

Fixed &Fixed::operator=(Fixed const &fixed)
{
    if (this != &fixed)
        _value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

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
    return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt() const
{
    return _value >> _bits;
}

bool Fixed::operator>(Fixed const &fixed) const
{
    return _value > fixed.getRawBits();
}

bool Fixed::operator<(Fixed const &fixed) const
{
    return _value < fixed.getRawBits();
}

bool Fixed::operator>=(Fixed const &fixed) const
{
    return _value >= fixed.getRawBits();
}

bool Fixed::operator<=(Fixed const &fixed) const
{
    return _value <= fixed.getRawBits();
}

bool Fixed::operator==(Fixed const &fixed) const
{
    return _value == fixed.getRawBits();
}

bool Fixed::operator!=(Fixed const &fixed) const
{
    return _value != fixed.getRawBits();
}

Fixed Fixed::operator+(Fixed const &fixed) const
{
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(Fixed const &fixed) const
{
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(Fixed const &fixed) const
{
    return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++()
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

Fixed &Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --_value;
    return temp;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b) ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return os;
}
