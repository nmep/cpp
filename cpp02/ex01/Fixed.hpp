#ifndef __FIXED__H__
	# define __FIXED__H__

	# include <iostream>
	# include <cmath>

	class Fixed
	{
		public:
			Fixed( void );
			Fixed( Fixed const &copy );
			Fixed( int const n);
			Fixed( float const n);
			Fixed &	operator=(Fixed const & other);
			~Fixed();

			int		getRawBits( void ) const;
			void	setRawBits( int const raw);
			float	toFloat ( void ) const;
			int		toInt( void ) const;

		private:
			int	_value;
			static int const _fractionBits = 8;
	};

std::ostream & operator<<(std::ostream & o, Fixed const & other);

# endif