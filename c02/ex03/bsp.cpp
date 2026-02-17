# include "Point.hpp"

static int	sign(Point const &v1, Point const &v2, Point const &test)
{
	Fixed sign	= (v2.y() - v1.y()) * test.x()
				- (v2.x() - v1.x()) * test.y()
				+ (v2.x() - v1.x()) * v1.y()
				- (v2.y() - v1.y()) * v1.x();
	return (sign == 0) ? 0 : (sign > 0) ? 1 : -1;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (sign(a, b, c) == 0)
		return (false);
		
	bool same_side_ab = (sign(a, b, c) == sign(a, b, point) && sign(a, b, point) != 0);
	bool same_side_ac = (sign(a, c, b) == sign(a, c, point) && sign(a, c, point) != 0);
	bool same_side_bc = (sign(b, c, a) == sign(b, c, point) && sign(b, c, point) != 0);

	return ( same_side_ab && same_side_ac && same_side_bc );
}