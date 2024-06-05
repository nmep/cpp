# include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	ScalarConverter	convert;

	if (ac != 2 || av[1][0] == '\0')
	{
		std::cerr << "Wrong arg number" << std::endl;
		return (2);
	}

	const std::string str = av[1];

	if (!convert.getType( str ))
	{
		std::cerr << "invalid arguments" << std::endl;
		return 2;
	}
	convert.convert(str);
}