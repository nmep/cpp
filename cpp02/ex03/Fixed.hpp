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
			~Fixed();

			bool	operator>(Fixed const & other);
			bool	operator<(Fixed const & other);
			bool	operator>=(Fixed const & other);
			bool	operator<=(Fixed const & other);
			bool	operator==(Fixed const & other);
			bool	operator!=(Fixed const & other);

			Fixed &	operator=(Fixed const & other);
			Fixed	operator+(Fixed const & other);
			Fixed	operator-(Fixed const & other);
			Fixed	operator*(Fixed const & other);
			Fixed	operator/(Fixed const & other);
			Fixed&	operator++();		
			Fixed	operator++(int);
			Fixed&	operator--();
			Fixed	operator--(int);

			static Fixed&	min(Fixed &a, Fixed &b);
			static const Fixed&	min(Fixed const &a, Fixed const &b);
			static Fixed&	max(Fixed &a, Fixed &b);
			static const Fixed&	max(Fixed const &a, Fixed const &b);

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