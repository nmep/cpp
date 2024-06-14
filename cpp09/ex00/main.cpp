# include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	// check arg
	if (ac != 2)
	{
		std::cout << "Usage ./btc <my_database_file>" << std::endl;
		return 2;
	}
	std::string infile(av[1]);
	bitcoinExchange a;
	// avoir la valeur stocke
	try
	{
		a.getMap(infile);
	}
	catch (invalidFile& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	// prend le file inpute
}
