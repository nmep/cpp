# include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongAnimal")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( const std::string type ) : WrongAnimal(type)
{
	std::cout << "Wrong Cat assignement constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat& copy) : WrongAnimal(copy._type)
{
	this->_type = copy._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

std::string	WrongCat::getType( void ) const
{
	return this->_type;
}

WrongCat&	WrongCat::operator=( WrongCat& rhs )
{
	this->_type = rhs._type;
	return *this;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat make " << this->_type << " sound" << std::endl;
}