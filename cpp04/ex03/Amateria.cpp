# include "Amateria.hpp"

AMateria::AMateria( void )
{
	std::cout << "Amateria default constructor" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << "Amaterica assignement constructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Amateria used on " << target.getName() << std::endl;
}