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
	return *this;
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

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	// if (this->_amateria_source[0] == NULL)
	// {
	// 	std::cout << "no ametria source was learned" << std::endl;
	// 	return ;
	// }
	for (int i = 0; i < 4; i++)
	{
		if (this->_amateria_source[i] == NULL || i == 3)
		{
			if (i > 0)
			{
				if (this->_amateria_source[i - 1]->getType() == type)
					return this->_amateria_source[i];
			}
			if (this->_amateria_source[i]->getType() == type)
				return this->_amateria_source[i];
		}
	}
	std::cout << "Materia unknow" << std::endl;
	return 0;
}
