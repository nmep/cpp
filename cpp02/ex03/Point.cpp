# include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const float x, const float y) : _x(x), _y(y) {}

Point::Point( const Point &copy ) : _x(copy.GetX()), _y(copy.GetY()) {}

Point::~Point() {}

float	Point::GetX( void ) const
{
	return this->_x.toFloat();
}

float	Point::GetY( void ) const
{
	return this->_y.toFloat();
}

Point	Point::operator=(Point &other)
{
	Point tmp;

	tmp = other;
	return tmp;
}

bool Check_ll_overflow(Point const p1, Point const p2, Point const p3)
{
	if ((p1.GetX() * (p2.GetY() - p3.GetY())) > INT_MAX
			|| (p1.GetX() * (p2.GetY() - p3.GetY())) <= INT_MIN)
	{
		std::cerr << "the result of the surface that take a side of the triangle is out overflow" << std::endl;
		return false;
	}
	return true;
}

bool	Check_air_and_surface_overflow(float *air, Point const p1, Point const p2, Point const p3)
{	
	if (*air + (p1.GetX() * (p2.GetY() - p3.GetY())) > INT_MAX
		|| *air + (p1.GetX() * (p2.GetY() - p3.GetY())) <= INT_MIN)
	{
		std::cerr << "the result of the surface that take a side of the triangle overflow" << std::endl;
		return false;
	}
	return true;
}

bool	Get_The_Triangle_Air(Point const p1, Point const p2, Point const p3, float *air)
{
	*air = ((p1.GetX() * p3.GetY()) - (p1.GetX() * p2.GetY()));
	*air += ((p2.GetX() * p1.GetY()) - (p2.GetX() * p3.GetY()));
	*air += ((p3.GetX() * p2.GetY()) - (p3.GetX() * p1.GetY()));
	if (*air < 0.0f)
		*air *= -1.0f;
	*air *= 0.5f;
	return true;
}

bool	is_point_on_segment(Point const p1, Point const p2, Point const p)
{
	int	dxc = p.GetX() - p1.GetX();
	int	dyc = p.GetY() - p1.GetY();

	int	dx1 = p2.GetX() - p1.GetX();
	int dy1 = p2.GetY() - p1.GetY();

	int	cross;

	cross = dxc * dy1 - dyc * dx1;
	if (cross != 0)
		return false;
	std::cout << "the point is on a segment or vertex of the triangle" << std::endl;
	return true;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	triangle_air;
	float	air1;
	float	air2;
	float	air3;

	if ((a.GetX() == b.GetX() && a.GetY() == b.GetY()) ||
		(b.GetX() == c.GetX() && b.GetY() == c.GetY()) ||
		(c.GetX() == a.GetX() && c.GetY() == a.GetY()))
	{
		std::cout << "The triangle is a line" << std::endl;
		return false;
	}
	// prendre l'air du triangle
	if (Get_The_Triangle_Air(a, b, c, &triangle_air) == false)
		return false;
	// prendre l'air air1
	// std::cout << "ici" << std::endl;
	if (Get_The_Triangle_Air(a, b, point, &air1) == false)
		return false;
	// prendre l'air air2
	if (Get_The_Triangle_Air(point, b , c, &air2) == false)
		return false;
	// prendre l'air air3
	if (Get_The_Triangle_Air(a, point, c, &air3) == false)
		return false;
	// faire la somme de air1 air2 air3
	if ((air1 + air2 + air3) <= INT_MIN || (air1 + air2 + air3) > INT_MAX)
	{
		std::cerr << "the some of the three air triangle / 2 overflow" << std::endl;
		return false;
	}
	// si c'est egal return true sinon return false
	if (is_point_on_segment(a, b, point) ||
		is_point_on_segment(b, c, point) ||
		is_point_on_segment(c, a, point))
		return false;
	if (air1 + air2 + air3 == triangle_air)
	{
		std::cout << "The point is in the triangle" << std::endl;
		return true;
	}
	std::cout << "the triangle is outside the triangle" << std::endl;
	return false;
}
