# include "Character.hpp"

Character::Character( void ) : _name("default")
{
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < this->_inventory_size; i++)
		this->_inventory[i] = NULL;
}

Character::Character( Character& copy ) : _name("default")
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < this->_inventory_size; i++)
	{
		this->_inventory[i] = NULL;
		this->_inventory[i] = copy._inventory[i]->clone();
	}
}

Character&	Character::operator=( Character& rhs )
{
	for (int i = 0; i < this->_inventory_size; i++)
	{
		if (this->_inventory[i] == NULL)
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
		{
			delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
}

Character::~Character()
{
	for (int i = 0; i < this->_inventory_size; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName( void ) const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < this->_inventory_size; i++)
	{
		if (this->_inventory[i] == NULL)
			this->_inventory[i] = m;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		this->_inventory[0] = NULL;
	}
	else
		std::cout << "index " << idx << "isnt good" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
		this->_inventory[idx]->use(target);
	else
		std::cout << idx << " is not in range of inventory" << std::endl;
}
