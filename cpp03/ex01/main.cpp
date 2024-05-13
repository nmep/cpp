# include "ScavTrap.hpp"

int	main()
{
	ScavTrap	player1("player1");
	ScavTrap	player2("player2");
	ClapTrap*	playertest = new ClapTrap("test");
	delete playertest;

	player1.attack("player2");
	player2.takeDamage(player1.GetAttackDamage());

	return (0);
}