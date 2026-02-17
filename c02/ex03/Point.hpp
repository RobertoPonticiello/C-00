#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <cmath>

class Point
{
    private:
    Fixed const _x;
    Fixed const _y;

    public:
    Point( void );
    Point( const float x, const float y);
    Point( Point const & other );
    ~Point( void );

    Point	&operator=(Point const &other);

    Fixed	x(void) const;
	Fixed	y(void) const;
};

#endif