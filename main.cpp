#include "Fixed.hpp"
#include <iostream>

int		main ( void ) {
	Fixed a ;
	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	a = Fixed(5);
	std::cout << "b = " << b << "\n";
	std::cout << "a = " << a << "\n";
	std::cout << "a * b = " << a * b << "\n";
	std::cout << "a / b = " << a / b << "\n";

	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << (Fixed(10) != Fixed(11)) << "\n";
	std::cout << (Fixed(10) == Fixed(11)) << "\n";
	std::cout << (Fixed(10) == Fixed(10)) << "\n";
	std::cout << (Fixed(10) > Fixed(9)) << "\n";
	std::cout << (Fixed(10) > Fixed(11)) << "\n";

	return 0;
}