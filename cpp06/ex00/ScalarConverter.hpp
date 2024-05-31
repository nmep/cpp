# ifndef SCALARCONVERTER_HPP
	# define SCALARCONVERTER_HPP

	# include <iostream>
	# include <string>
	# include <sstream>
	# include "ScalarConverter.hpp"

	class ScalarConverter
	{
		public:
			ScalarConverter( void );
			virtual ~ScalarConverter();
			// ScalarConverter( const ScalarConverter& copy );
			ScalarConverter& operator=( ScalarConverter& rhs );

			// class ImpossibleException : public std::exception
			// {
			// 	public:
			// 		virtual const char *what(void) const throw();
			// };
			// class NonDisplayable : public std::exception
			// {
			// 	public:
			// 		virtual const char *what(void) const throw();
			// };
			// class NoType : public std::exception
			// {
			// 	public:
			// 		virtual const char *what(void) const throw();
			// };

	};

	class ImpossibleException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};
	class NonDisplayable : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};
	class NoType : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

void	getType( const std::string& str );

# endif