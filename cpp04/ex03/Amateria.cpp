# include "Amateria.hpp"

AMateria::AMateria( void ) : _type("default")
{
	std::cout << "Amateria default constructor" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << "Amaterica assignement constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Amateria destructor" << std::endl;
}

AMateria &	AMateria::operator=(AMateria& rhs)
{
	this->_type = rhs._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Amateria used on " << target.getName() << std::endl;
}