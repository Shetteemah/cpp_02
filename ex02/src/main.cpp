#include "../include/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a begins with:\t\t" << a << std::endl;
	std::cout << "value of a at ++a:\t" << ++a << std::endl;
	std::cout << "value of a after ++a:\t" << a << std::endl;
	std::cout << "value of a at a++:\t" << a++ << std::endl;
	std::cout << "value of a after a++:\t" << a << std::endl;
	std::cout << "value of b:\t\t" << b << std::endl;

	std::cout << "max value of a & b:\t" << Fixed::max( a, b ) << std::endl;
	std::cout << "min value of a & b:\t" << Fixed::min( a, b ) << std::endl;

	return (0);
}