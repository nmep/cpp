#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << ANSI_COLOR_GREEN << "Zombie " << this->_name << " created." << ANSI_COLOR_RESET << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << ANSI_COLOR_RED << this->_name << " destroyed." << ANSI_COLOR_RESET << std::endl;
}

void	Zombie::announce (void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}