#ifndef Fixed_HPP
#define Fixed_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
    int num;
    static const int num_fb = 8;

    public:
    Fixed( void );
    Fixed( const int n);
    Fixed( const float n);

    Fixed( Fixed const & other );
    ~Fixed( void );

    Fixed & operator=(Fixed const &other);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    static Fixed & min(Fixed & a, Fixed & b);
    static Fixed & max(Fixed & a, Fixed & b);
    static const Fixed & min(Fixed const & a, Fixed const & b);
    static const Fixed & max(Fixed const & a, Fixed const & b);

    Fixed & operator++( void );
    Fixed & operator--( void );
    Fixed operator++( int );
    Fixed operator--( int );
};

std::ostream & operator<<(std::ostream & o, Fixed const & input);

#endif