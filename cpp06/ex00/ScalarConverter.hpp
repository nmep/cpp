# ifndef SCALARCONVERTER_HPP
	# define SCALARCONVERTER_HPP

	# include <iostream>
	# include <string>
	# include <sstream>
	# include "Exception.hpp"
	# include <bits/stdc++.h>

	# define CHAR 1
	# define INT 2
	# define FLOAT 3
	# define DOUBLE 4
	# define NotANumber 5
	# define INF 6
	class ScalarConverter
	{
		private:
			bool impossible;
			bool nonDisplay;
			int	type;

		public:
			int	getType( const std::string& str);
			int ft_is_float( const std::string str );
			int	ft_is_double( const std::string& str);
			int	ft_is_INT( const std::string& str );
			int	ft_is_C(const std::string& str);
			
			void	ft_print_C( const std::string& arg );
			void	ft_print_INT( const std::string& arg);
			void	ft_print_Float( const std::string& arg);
			void	ft_print_double( const std::string& arg);

			ScalarConverter( void );
			virtual ~ScalarConverter();
			// ScalarConverter( const ScalarConverter& copy );
			ScalarConverter& operator=( ScalarConverter& rhs );
			void convert( const std::string &arg );
	};

int	getType( const std::string& str , int *type, bool *Impossible, bool *nonDisplay);

# endif