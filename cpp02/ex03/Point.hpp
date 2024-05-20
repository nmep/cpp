# ifndef	POINT_HPP
	# define	POINT_HPP

	#include "Fixed.hpp"
	# include <limits.h>

	class Point
	{
		private:
			const	Fixed _x;
			const	Fixed _y;
			// ce qui m'ait utile

		public:
			Point(void);
			Point( const float x, const float y);
			Point ( const Point &Point);
			~Point();

			float	GetX( void ) const;
			float	GetY( void ) const;
			Point	operator=(Point &rhs);
			// Point&	operator*(Point &rhs);
			// tout ce qui peux m'ettre utile
	};

	bool	is_point_on_segment(Point const p1, Point const p2, Point const p);
	bool	Check_air_and_surface_overflow(float *air, Point const p1, Point const p2, Point const p3);
	bool	Check_ll_overflow(Point const p1, Point const p2, Point const p3);
	bool	Get_The_Triangle_Air(Point const p1, Point const p2, Point const p3, float *air);
	bool	bsp( Point const a, Point const b, Point const c, Point const point);
# endif