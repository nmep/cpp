#include "Weapon.hpp"

Weapon::Weapon(std::string const type) : _type(type)
{
	std::cout << "Weapon constructor" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destructor" << std::endl;
}

std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void			Weapon::setType(std::string const type)
{
	this->_type = type;
}