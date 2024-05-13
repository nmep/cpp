# ifndef	POINT_HPP
	# define	POINT_HPP

	#include "Fixed.hpp"

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

			Point&	operator=(const Fixed &rhs);

			bool	bsp( Point const a, Point const b, Point const c, Point const point);
			// tout ce qui peux m'ettre utile
	}

# endif