# include "Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat")
{
	std::cout << "Cat constructor called for " << this->_type << std::endl;
}

Cat::Cat( const std::string type ) : AAnimal(type)
{
	std::cout << "Cat assignement constructor called for " << this->_type << std::endl;
}

Cat::Cat( Cat& copy ) : AAnimal(copy._type)
{
	std::cout << "Cat copy constructor called for " << this->_type << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called for " << this->_type << std::endl;
}

Cat&	Cat::operator=( Cat& rhs )
{
	this->_type = rhs._type;
	return *this;
}

std::string	Cat::getType( void ) const
{
	return this->_type;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Cat make " << this->_type << " Sound" << std::endl;
}