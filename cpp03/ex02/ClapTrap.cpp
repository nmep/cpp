# include "ClapTrap.hpp"

// -------------------------- CONSTRUCTEUR / DESTRUCTEUR --------------------- //

ClapTrap::ClapTrap( void )
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string name ) : _name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(10)
{
	std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy )
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for " << this->_name << std::endl;
}

// -------------------------- GETTEUR --------------------- //

const std::string	ClapTrap::GetName( void )
{
	return this->_name;
}

unsigned int	ClapTrap::GetHitPoint( void )
{
	return this->_HitPoint;
}

unsigned int	ClapTrap::GetEnergyPoint( void )
{
	return this->_EnergyPoint;
}

unsigned int	ClapTrap::GetAttackDamage( void )
{
	return this->_AttackDamage;
}

// -------------------------- Function membre --------------------- //

void	ClapTrap::attack( const std::string & target )
{
	if (this->_EnergyPoint == 0)
	{
		std::cout << "ClapTrap Energy point is 0 " << GetName() << " can't attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << GetName() << " attacks " << target << " causing " << GetAttackDamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HitPoint <= 0)
	{
		std::cout << "ClapTrap " << GetName() << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << GetName() << " take " << amount << " damage" << std::endl;
	this->_HitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_HitPoint += amount;
	std::cout << "ClapTrap " << GetName() << " is now " << GetHitPoint() << std::endl;
}

// -------------------------- surcharge d'operateur --------------------- //

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	this->_name = rhs._name;
	this->_HitPoint = rhs._HitPoint;
	this->_EnergyPoint = rhs._EnergyPoint;
	this->_AttackDamage = rhs._AttackDamage;
	std::cout << "ClapTrap " << GetName() << " has been copied" << std::endl;
	return *this;
}