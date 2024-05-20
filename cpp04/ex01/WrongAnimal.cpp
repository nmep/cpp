# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const std::string type ) : _type(type)
{
	std::cout << "Wrong AAnimal assignement constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
	this->_type = copy._type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return this->_type;
}

WrongAnimal&	WrongAnimal::operator=( WrongAnimal& rhs )
{
	this->_type = rhs._type;
	return *this;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal make " << this->_type << " sound" << std::endl;
}