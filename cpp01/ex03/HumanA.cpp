# include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& rand_Weapon) : _Weapon(rand_Weapon), _name(name)
{
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "Human A destructor" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_Weapon.getType() << std::endl;
}