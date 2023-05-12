#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(const int raw);

private:
    int fixedPointValue;
    static const int fractionalBits = 8;
};

#endif
