# include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Wrong arg number" << std::endl;
		return (2);
	}
	std::stringstream ss(av[1]);
	int n;

	ss >> n;

	if (ss.fail())
	{
		std::cerr << "problem" << std::endl;
		return 1;
	}
	std::cout << n;
	getType( av[1] ); 
}