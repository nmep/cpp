# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamonTrap default constructor called" << std::endl;
	// std::cout << "claptrap name = " << ClapTrap::GetName();
}

DiamondTrap::DiamondTrap( const std::string name ) : ClapTrap::ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_HitPoint = FragTrap::_HitPoint;
	this->_EnergyPoint = ScavTrap::_EnergyPoint;
	this->_attackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::WhoAmI( void )
{
	std::cout << "Diamond Trap Name " << this->_name << " Clap Trap name is "  << ClapTrap::_name << std::endl;
}

const std::string	DiamondTrap::GetName( void )
{
	return this->_name;
}