// #include "Fixed.hpp"

// Fixed::Fixed() : _value(0) {}

// Fixed::Fixed(const int value)
// {
//     _value = value << _bits;
// }

// Fixed::Fixed(const float value)
// {
//     _value = roundf(value * (1 << _bits));
// }

// Fixed::Fixed(const Fixed& other)
// {
//     *this = other;
// }

// Fixed& Fixed::operator=(const Fixed& other)
// {
//     if (this != &other)
//         _value = other.getRawBits();
//     return *this;
// }

// int Fixed::getRawBits() const
// {
//     return _value;
// }

// void Fixed::setRawBits(const int raw)
// {
//     _value = raw;
// }

// float Fixed::toFloat() const
// {
//     return (float)_value / (float)(1 << _bits);
// }

// int Fixed::toInt() const
// {
//     return _value >> _bits;
// }

// bool operator==(const Fixed& a, const Fixed& b)
// {
//     return a.getRawBits() == b.getRawBits();
// }

// bool operator!=(const Fixed& a, const Fixed& b)
// {
//     return a.getRawBits() != b.getRawBits();
// }

// bool operator<(const Fixed& a, const Fixed& b)
// {
//     return a.getRawBits() < b.getRawBits();
// }

// bool operator>(const Fixed& a, const Fixed& b)
// {
//     return a.getRawBits() > b.getRawBits();
// }

// bool operator<=(const Fixed& a, const Fixed& b)
// {
//     return a.getRawBits() <= b.getRawBits();
// }

// bool operator>=(const Fixed& a, const Fixed& b)
// {
//     return a.getRawBits() >= b.getRawBits();
// }

// Fixed& Fixed::operator++()
// {
//     _value += 1;
//     return *this;
// }

// Fixed Fixed::operator++(int)
// {
//     Fixed tmp(*this);
//     operator++();
//     return tmp;
// }

// Fixed& Fixed::operator--()
// {
//     _value -= 1;
//     return *this;
// }

// Fixed Fixed::operator--(int)
// {
//     Fixed tmp(*this);
//     operator--();
//     return tmp;
// }

// Fixed operator+(const Fixed& a, const Fixed& b)
// {
//     return Fixed(a.toFloat() + b.toFloat());
// }

// Fixed operator-(const Fixed& a, const Fixed& b)
// {
//     return Fixed(a.toFloat() - b.toFloat());
// }

// Fixed operator*(const Fixed& a, const Fixed& b)
// {
//     return Fixed(a.toFloat() * b.toFloat());
// }

// Fixed operator/(const Fixed& a, const Fixed& b)
// {
//     return Fixed(a.toFloat() / b.toFloat());
// }

// std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
// {
//     os << fixed.toFloat();
//     return os;
// }

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(int const value) : value(value << bits) {}

Fixed::Fixed(float const value) : value(roundf(value * (1 << bits))) {}

Fixed::Fixed(Fixed const &fixed) : value(fixed.getRawBits()) {}

Fixed &Fixed::operator=(Fixed const &fixed)
{
    if (this != &fixed)
        value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const { return value; }

void Fixed::setRawBits(int const raw) { value = raw; }

float Fixed::toFloat() const { return (float)value / (1 << bits); }

int Fixed::toInt() const { return value >> bits; }

bool Fixed::operator>(Fixed const &fixed) const { return value > fixed.getRawBits(); }

bool Fixed::operator<(Fixed const &fixed) const { return value < fixed.getRawBits(); }

bool Fixed::operator
