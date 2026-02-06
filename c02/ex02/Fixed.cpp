#include "Fixed.hpp"

Fixed::Fixed()
{
    this->num = 0;
}

Fixed::Fixed(const int n)
{
    this->num = n << this->num_fb;
}

Fixed::Fixed(const float n)
{
    this->num = (int)roundf(n * (1 << this->num_fb));
}

Fixed::Fixed(Fixed const &other)
{
    this->num = other.getRawBits();
}

Fixed::~Fixed() {}

Fixed & Fixed::operator=(const Fixed &other)
{
	this->num = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->num > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->num < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return(this->num >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return(this->num <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return(this->num == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return(this->num != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->num + other.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->num - other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long long tmp = (long long)this->num * (long long)other.num;
    result.setRawBits((int)(tmp >> this->num_fb));
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed		result;
    long long	dividend = (long long)this->num << this->num_fb;
    result.setRawBits((int)(dividend / other.getRawBits()));
	return (result);
}

Fixed & Fixed::operator++( void )
{
    this->num++;
    return(*this);
}

Fixed & Fixed::operator--( void )
{
    this->num--;
    return(*this);
}

Fixed Fixed::operator++( int )
{
    Fixed tmp(*this);
    this->num++;
    return(tmp);
}

Fixed Fixed::operator--( int )
{
    Fixed tmp(*this);
    this->num--;
    return(tmp);
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b)
{
    return ((a.num <= b.num) ? a : b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    return ((a.num <= b.num) ? a : b);
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b)
{
    return ((a.num >= b.num) ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    return ((a.num >= b.num) ? a : b);
}

int Fixed::getRawBits( void ) const
{
    return (this->num);
}

void Fixed::setRawBits( int const raw )
{
    this->num = (int)raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->num / (1 << this->num_fb));
}

int Fixed::toInt( void ) const
{
    return(this->num >> this->num_fb);
}

std::ostream & operator<<(std::ostream & o, Fixed const & input)
{
	o << input.toFloat();
	return (o);
}