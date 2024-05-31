# ifndef EXCEPTION_HPP
	# define EXCEPTION_HPP

	# include <iostream>

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

# endif