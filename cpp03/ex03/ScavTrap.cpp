# include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor " << this->_name << std::endl;
}

ScavTrap::ScavTrap( const std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap asignment constructor called for " << this->_name << std::endl;
	this->_HitPoint = 100;
	this->_EnergyPoint = 50;
	this->_AttackDamage = 20;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_EnergyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack" << std::endl;
		return ;
	}
	std::cout << "ScaveTrap " << this->_name << " attack " << target << std::endl;
	this->_EnergyPoint--;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

std::string	ScavTrap::GetName( void )
{
	return (this->_name);
}