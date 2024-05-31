# include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	ScalarConverter	convert;
	int	type = 0;
	bool	impossible = false;
	bool	nonDisplay = false;
	if (ac != 2)
	{
		std::cerr << "Wrong arg number" << std::endl;
		return (2);
	}
	std::stringstream ss(av[1]);
	float n;

	ss >> n;

	std::cout << '[' << n << ']' << std::endl;
	if (!getType( av[1] , &type, &impossible, &nonDisplay))
	{
		std::cerr << "invalid arguments" << std::endl;
		return 2;
	}
	std::cout << "type = " << type << std::endl;
	// verfier si get type = 0 si gettype est a 0 et que
	// les booleans sont a false c'est qu'il y a un invalid
	// argument et qu'aucun type n'a ete detecte.
}