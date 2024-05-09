#ifndef	__FIXED__
	# define	__FIXED__

	# include <iostream>

	class Fixed
	{
		public:
			Fixed( void );
			Fixed( Fixed &copy );
			Fixed &	operator=(Fixed const & other);
			~Fixed();

			int		getRawBits( void ) const;
			void	setRawBits( int const raw);

		private:
			int	_value;
			static int const _fractionBits;
	};

# endif