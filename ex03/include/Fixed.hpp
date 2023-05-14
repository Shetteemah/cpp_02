#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits;
    
    public:
        Fixed();
        Fixed(int const value);
        Fixed(float const value);
        Fixed(Fixed const &fixed);
        ~Fixed();
        Fixed &_operator=(const Fixed &fixed);
    
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    
        bool operator>(Fixed fixed) const;
        bool operator<(Fixed fixed) const;
        bool operator>=(Fixed fixed) const;
        bool operator<=(Fixed fixed) const;
        bool operator==(Fixed fixed) const;
        bool operator!=(Fixed fixed) const;
    
        Fixed operator+(Fixed fixed) const;
        Fixed operator-(Fixed fixed) const;
        Fixed operator*(Fixed fixed) const;
        Fixed operator/(Fixed fixed) const;
    
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
    
        static Fixed const &min(Fixed const &a, Fixed const &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

// #include "../include/Point.hpp"
#endif
