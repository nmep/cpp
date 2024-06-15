# include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	// check arg
	if (ac != 2)
	{
		std::cout << "Usage ./btc <my_database_file>" << std::endl;
		return 2;
	}
	bitcoinExchange a;
	// avoir la valeur stocke
	try
	{
		a.getMap("data.csv");
	}
	catch (invalidFile& e)
	{
		std::cerr << RED << "data file " << e.what() << RESET << '\n';
		return (1);
	}
	// std::cout << a;
	
	std::string infileStr(av[1]);

	try
	{
		a.getInMap(infileStr);
	}
	catch(invalidFile& e)
	{
		std::cerr << e.what() << '\n';
	}
	// ouvrir le fichier entrant
	// split la donee et l'insserer dans in_m
	// verifier si la value est correct
	

}
