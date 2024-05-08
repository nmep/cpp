# include "Sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "./exec <filename> s1 s2" << std::endl;
		return (2);
	}
	std::string av1 (av[1]);
	std::string av2 (av[2]);
	std::string av3 (av[3]);
	if (av2.length() == 0 || av3.length() == 0)
	{
		std::cerr << "Empty s1 or s2" << std::endl;
		return (2);
	}
	std::ifstream ifs;
	ifs.open(av[1], std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cerr << "Error opening the input file" << std::endl;
		return (0);
	}
	av1.append(".replace");
	std::ofstream ofs (av1.c_str());
	std::string	word;
	while (ifs >> word)
	{
		if (word == av2)
			word = av3;
		ofs << word;
		if (ifs.peek() != EOF)
			ofs << " ";
	}
	ifs.close();
	ofs.close();
	return (0);
}