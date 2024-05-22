# include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _type("default")
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_amateria_source[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource& copy ) : _type(copy._type)
{
	std::cout << "Materiasource copy constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_amateria_source[i] = copy._amateria_source[i];
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=( MateriaSource& rhs )
{
	this->_type = rhs._type;
	for (int i = 0; i < 4; i++)
		this->_amateria_source[i] = rhs._amateria_source[i];
}

void	MateriaSource::learnMateria( AMateria* learn )
{
	if (!learn)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_amateria_source[i] == NULL)
			this->_amateria_source[i] = learn->clone();
	}
	delete learn;
}
