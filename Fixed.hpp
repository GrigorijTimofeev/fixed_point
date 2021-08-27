#pragma once
#include <iostream>

class	Fixed {

private:
	static const int	_fractionalBits = 8;
	int					_value;

public:
	Fixed( void );
	Fixed( int val );
	Fixed( float val );
	Fixed( const Fixed &a );
	~Fixed( void );
	static Fixed& min( Fixed& f1, Fixed& f2 );
	static const Fixed& min( const Fixed& f1, const Fixed& f2 );
	static Fixed& max( Fixed& f1, Fixed& f2 );
	static const Fixed& max( const Fixed& f1, const Fixed& f2 );
	Fixed&	operator= (const Fixed &number);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed&	operator++ ( void ); // prefix
	Fixed&	operator-- ( void ); // prefix
	Fixed	operator++ ( int ); // postfix
	Fixed	operator-- ( int ); // postfix
	friend std::ostream& operator<< ( std::ostream& out, const Fixed &point );
	friend bool operator== ( const Fixed &f1, const Fixed &f2 );
	friend bool operator!= ( const Fixed &f1, const Fixed &f2 );
	friend bool operator>= ( const Fixed &f1, const Fixed &f2 );
	friend bool operator<= ( const Fixed &f1, const Fixed &f2 );
	friend bool operator> ( const Fixed &f1, const Fixed &f2 );
	friend bool operator< ( const Fixed &f1, const Fixed &f2 );
	friend Fixed operator+ ( const Fixed &f1, const Fixed &f2 );
	friend Fixed operator- ( const Fixed &f1, const Fixed &f2 );
	friend Fixed operator* ( const Fixed &f1, const Fixed &f2 );
	friend Fixed operator/ ( const Fixed &f1, const Fixed &f2 );

};