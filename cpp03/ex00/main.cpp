# include "ClapTrap.hpp"

int	main()
{
	ClapTrap	player1("player1");
	ClapTrap	player2("player2");

	player1.attack("player2");
	std::cout << "Before attack " << player1.GetName() << " has " << player1.GetHitPoint() << " hit point" << std::endl;
	player1.takeDamage(2);
	std::cout << "After attack " << player1.GetName() << " has " << player1.GetHitPoint() << " hit point" << std::endl;

	player1.beRepaired(2);
	std::cout << std::endl;
	std::cout << std::endl;
	// ----------------- //

	player2.attack("player1");
	player1.takeDamage(player2.GetAttackDamage());
}