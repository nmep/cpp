# include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog")
{
	std::cout << "Dog default constructor called for " << this->_type << std::endl;
}

Dog::Dog( const std::string type) : AAnimal(type)
{
	std::cout << "Dog assignation constructor called for " << this->_type << std::endl;
}

Dog::Dog( Dog& copy ) : AAnimal(copy.getType())
{
	std::cout << "Dog copy constructor called for " << this->_type << std::endl;
}

std::string	Dog::getType( void ) const
{
	return this->_type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for " << this->_type << std::endl;
}

Dog&	Dog::operator=( Dog& rhs )
{
	this->_type = rhs.getType();
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Dog make " << this->_type << " Sound" << std::endl;
}