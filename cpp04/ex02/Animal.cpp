# include "Animal.hpp"

AAnimal::AAnimal( void ) : _type("AAnimal")
{
	std::cout << MAGENTA << "AAnimal default Constructor called type is set to AAnimal" << RESET << std::endl;
}

AAnimal::AAnimal( const std::string name) : _type(name)
{
	std::cout << MAGENTA << "AAnimal assignation constructor called for " << _type << RESET << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << MAGENTA << "AAnimal Destructor called for " << this->_type << RESET << std::endl;
}

std::string	AAnimal::getType( void ) const
{
	return this->_type;
}

AAnimal& AAnimal::operator=(AAnimal& other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->_type = other.getType();
	return *this;
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "AAnimal make " << this->_type << " sound" << std::endl;
}