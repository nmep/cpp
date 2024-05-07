# include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_Weapon = NULL;
	std::cout << "HumanB constructor" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destructor" << std::endl;
}

void	HumanB::setWeapon(Weapon &rand_Weapon)
{
	this->_Weapon = &rand_Weapon;
}

void	HumanB::attack(void) const
{
	if (this->_Weapon == NULL || this->_Weapon->getType() == "")
		std::cout << this->_name << " attacks without weapon " << std::endl;
	else
		std::cout << this->_name << " attacks with their " << (this->_Weapon)->getType()  << std::endl;
}