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
		public:
			ScalarConverter( void );
			virtual ~ScalarConverter();
			// ScalarConverter( const ScalarConverter& copy );
			ScalarConverter& operator=( ScalarConverter& rhs );
	};

int	getType( const std::string& str , int *type, bool *Impossible, bool *nonDisplay);

# endif