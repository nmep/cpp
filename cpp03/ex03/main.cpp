# include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	monster("toto");

	std::cout << std::endl;
	monster.attack("enemy");
	monster.guardGate();
	monster.highFivesGuys();

	std::cout << std::endl;
	std::cout << "Clap trap name " << monster.ClapTrap::GetName() << " | monster name " << monster.DiamondTrap::GetName() << std::endl;
	return (0);
}