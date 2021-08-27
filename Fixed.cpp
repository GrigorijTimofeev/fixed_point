#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed ( void ) : _value(0) {
}

Fixed::Fixed ( int val ) {
	this->_value = val << this->_fractionalBits;
}

Fixed::Fixed ( float val ) {
	this->_value = (val * (float)(1 << this->_fractionalBits));
}

Fixed::Fixed ( const Fixed &a )
		: _value(a._value) {
}

Fixed::~Fixed ( void ) {
};

Fixed&	Fixed::operator= ( const Fixed &number) {
	this->_value = number._value;

	return *this;
}

int		Fixed::getRawBits( void ) const {
	return this->_value;
}

void	Fixed::setRawBits ( int const raw ) {
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->_value / (float)(1 << this->_fractionalBits);
}

int		Fixed::toInt( void ) const {
	return this->_value >> this->_fractionalBits;
}

std::ostream& operator<< ( std::ostream& out, const Fixed &point ) {
	out << point.toFloat();
	
	return out;
}

Fixed&	Fixed::min( Fixed& f1, Fixed& f2 ) {
	return ( f1  < f2 ) ? f1 : f2;
}

const Fixed&	Fixed::min( const Fixed& f1, const Fixed& f2 ) {
	return ( f1  < f2 ) ? f1 : f2;
}

Fixed&	Fixed::max( Fixed& f1, Fixed& f2 ) {
	return ( f1  > f2 ) ? f1 : f2;
}

const Fixed&	Fixed::max( const Fixed& f1, const Fixed& f2 ) {
	return ( f1  > f2 ) ? f1 : f2;
}

bool operator== ( const Fixed &f1, const Fixed &f2 ) {
	return (f1._value == f2._value);
}

bool operator!= ( const Fixed &f1, const Fixed &f2 ) {
	return !(f1 == f2);
}

bool operator> ( const Fixed &f1, const Fixed &f2 ) {
	return (f1._value > f2._value);
}

bool operator< ( const Fixed &f1, const Fixed &f2 ) {
	return (f1._value < f2._value);
}

bool operator>= ( const Fixed &f1, const Fixed &f2 ) {
	return (f1._value >= f2._value);
}

bool operator<= ( const Fixed &f1, const Fixed &f2 ) {
	return (f1._value <= f2._value);
}

Fixed operator+ ( const Fixed &f1, const Fixed &f2 ) {
	return Fixed( f1.toFloat() + f2.toFloat() );
}

Fixed operator- ( const Fixed &f1, const Fixed &f2 ) {
	return Fixed( f1.toFloat() - f2.toFloat() );
}

Fixed operator* ( const Fixed &f1, const Fixed &f2 ) {
	return (f1.toFloat() * f2.toFloat());
}

Fixed operator/ ( const Fixed &f1, const Fixed &f2 ) {
	return (f1.toFloat() / f2.toFloat());
}

Fixed& Fixed::operator++ ( void ) {
	this->_value++;
	return *this;
}

Fixed& Fixed::operator-- ( void ) {
	this->_value--;
	return *this;
}

Fixed	Fixed::operator++ ( int ) {
	Fixed	tmp(*this);
	
	++(*this);
	
	return tmp;
}

Fixed	Fixed::operator-- ( int ) {
	Fixed	tmp(*this);
	
	--(*this);
	
	return tmp;
}

