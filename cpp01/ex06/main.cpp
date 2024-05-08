# include "Harl.hpp"

int	main()
{
	Harl		harl;
	std::string	line;

	while (std::cin)
	{
		if (std::cin.eof() || std::cin.fail())
		{
			std::cin.clear();
			std::cerr << "EOF or Fail" << std::endl;
			return (2);
		}
		if (!getline(std::cin, line))
		{
			std::cerr << "EOF" << std::endl;
			return (2);
		}
		else
		{
			if (line.length() > 0)
				harl.complain(line);
		}
	}
}