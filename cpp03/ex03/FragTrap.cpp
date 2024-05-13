# include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap default Constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string name) : ClapTrap(name)
{
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap assignmenet constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_EnergyPoint <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't attack" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << " causing " << this->_AttackDamage << " point of damage!" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " is doing a high five" << std::endl;
}