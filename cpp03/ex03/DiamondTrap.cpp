# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamonTrap default constructor called" << std::endl;
	// std::cout << "claptrap name = " << ClapTrap::GetName();
}

DiamondTrap::DiamondTrap( const std::string name ) : ClapTrap::ClapTrap(name), _name(name)
{
	std::cout << "DiamondTrap Construct assignement" << std::endl;
	std::cout << ClapTrap::GetName() << std::endl;
	std::cout << "qwre " << ScavTrap::GetName() << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}