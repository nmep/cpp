# include "Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat")
{
	std::cout << GREEN << "Cat default constructor called for " << this->_type << RESET << std::endl;
	this->brain = new Brain;
}

Cat::Cat( const std::string type ) : AAnimal(type)
{
	std::cout << GREEN << "Cat assignement constructor called for " << this->_type << RESET << std::endl;
	this->brain = new Brain;
}

Cat::Cat( Cat& copy ) : AAnimal(copy._type)
{
	std::cout << GREEN << "Cat copy constructor called for " << this->_type << RESET << std::endl;
	this->brain = new Brain;
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat destructor called for " << this->_type << RESET << std::endl;
	delete this->brain;
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
	std::cout << GREEN << "Cat make " << this->_type << " Sound" << RESET << std::endl;
}

void	Cat::setIdea( const std::string idea )
{
	this->brain->setIdea(idea);
}
