#include "Zombie.hpp"

int	main()
{
	Zombie	*Horde_zombie = zombieHorde(10, "zomblar");

	delete [] Horde_zombie;
	return(0);
}