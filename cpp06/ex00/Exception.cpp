# include "Exception.hpp"

const char* ImpossibleException::what( void ) const throw()
{
	return "Impossible";
}
 
const char*	NonDisplayable::what( void ) const throw()
{
	return "Non Displayable";
}

const char * NoType::what() const throw()
{
	return "Not a type";
}
