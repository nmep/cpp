# include "Cure.hpp"

Cure::Cure( void ) : AMateria::AMateria("cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure( const Cure& copy) : AMateria("cure")
{
	*this = copy;
	std::cout << "Cure copy constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

Cure& Cure::operator=( const Cure& rhs )
{
	this->_type = rhs._type;
	return *this;
}

Cure*	Cure::clone( void ) const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
