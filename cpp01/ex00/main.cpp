#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie2 = newZombie("dynamic");
	delete zombie2;
	Zombie	zombie1("statique");
	zombie1.announce();
	randomChump("random");
	return (0);
}