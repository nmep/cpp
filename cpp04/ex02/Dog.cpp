# include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog")
{
	std::cout << BLUE << "Dog default constructor called for " << this->_type << RESET << std::endl;
	this->brain = new Brain;
}

Dog::Dog( const std::string type) : AAnimal(type)
{
	std::cout << BLUE << "Dog assignation constructor called for " << this->_type << RESET << std::endl;
	this->brain = new Brain;
}

Dog::Dog( Dog& copy ) : AAnimal(copy.getType())
{
	std::cout << BLUE << "Dog copy constructor called for " << this->_type << RESET << std::endl;
	this->brain = new Brain;
}

std::string	Dog::getType( void ) const
{
	return this->_type;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog destructor called for " << this->_type << RESET << std::endl;
	delete this->brain;
}

Dog&	Dog::operator=( Dog& rhs )
{
	this->_type = rhs.getType();
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << BLUE << "Dog make " << this->_type << " Sound" << RESET << std::endl;
}

void	Dog::setIdea( const std::string idea )
{
	this->brain->setIdea(idea);
}