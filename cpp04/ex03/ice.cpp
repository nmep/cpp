# include "Ice.hpp"

Ice::Ice( void ) : AMateria::AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice & ice ) : AMateria::AMateria("ice")
{
	std::cout << "Ice assignement constructor called" << std::endl;
	*this = ice;
}

Ice&	Ice::operator=( const Ice& rhs )
{
	this->_type = rhs._type;
	return *this;
}

Ice	*Ice::clone( void ) const
{
	return(new Ice(*this));
}

Ice::~Ice()
{
	std::cout << "Ice constructor called" << std::endl;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
