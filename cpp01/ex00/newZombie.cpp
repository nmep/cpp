# include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	// creer un zombie
	// lui donner un nom
	Zombie *zombie = new Zombie(name);
	// retourner le zombie
	return (zombie);
}