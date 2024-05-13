# include "FragTrap.hpp"

int	main()
{
	FragTrap	defaultFrag;
	FragTrap	player1("player1");
	FragTrap	player2("player2");

	// moove player1

	player1.attack("player2");
	std::cout << "player2 before getting dmg hitPoint " << player2.GetHitPoint() << std::endl;
	player2.takeDamage(player1.GetAttackDamage());
	std::cout << "player2 after getting dmg hitPoint " << player2.GetHitPoint() << std::endl;
	player2.beRepaired(player1.GetAttackDamage());
	player1 = player2;
	player1.highFivesGuys();
	return (0);
}