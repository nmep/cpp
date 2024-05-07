#include "Zombie.hpp"

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << ANSI_COLOR_BLUE << this->_name << ": BraiiiiiiinnnzzzZ..." << ANSI_COLOR_RESET << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << ANSI_COLOR_GREEN << "Zombie " << this->_name << " created" << ANSI_COLOR_RESET << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << ANSI_COLOR_RED << "Zombie " << this->_name << " deleted" << ANSI_COLOR_RESET << std::endl;
}

