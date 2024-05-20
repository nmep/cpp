# include "ClapTrap.hpp"

// -------------------------- CONSTRUCTEUR / DESTRUCTEUR --------------------- //


ClapTrap::ClapTrap( void )
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_HitPoint = 10;
	this->_EnergyPoint = 10;
	this->_AttackDamage = 0;
}

ClapTrap::ClapTrap( const std::string name) : _name(name)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_HitPoint = 10;
	this->_EnergyPoint = 10;
	this->_AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// -------------------------- GETTEUR --------------------- //

const std::string	ClapTrap::GetName( void )
{
	return this->_name;
}

int	ClapTrap::GetHitPoint( void )
{
	return this->_HitPoint;
}

int	ClapTrap::GetEnergyPoint( void )
{
	return this->_EnergyPoint;
}

int	ClapTrap::GetAttackDamage( void )
{
	return this->_AttackDamage;
}

// -------------------------- SETTEUR --------------------- //

void	ClapTrap::attack( const std::string & target )
{
	if (this->_EnergyPoint <= 0)
	{
		std::cout << "ClapTrap Energy point is 0 " << GetName() << " can't attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << GetName() << " attacks " << target << " causing " << GetAttackDamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(int amount)
{
	if (this->_HitPoint <= 0)
	{
		std::cout << "ClapTrap " << GetName() << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << GetName() << " take " << amount << " damage" << std::endl;
	this->_HitPoint -= amount;
}

void	ClapTrap::beRepaired(int amount)
{
	this->_HitPoint += amount;
	std::cout << "ClapTrap " << GetName() << "is now " << GetHitPoint() << std::endl;
}