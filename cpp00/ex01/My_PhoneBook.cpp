# include "PhoneBook.class.hpp"

int	main()
{
	PhoneBook		pb;
	std::string		line;
	int				i = 0;
	int				nb_contact = 0;

	while (std::cin)
	{
		std::cout << ANSI_COLOR_BLUE << "SEARCH ADD EXIT:" << ANSI_COLOR_RESET << std::endl << "$> ";
		if (!pb.ft_get_line(&line))
			return (2);
		if (!pb.ft_check_line(line))
			continue ;
		if (line == "ADD")
		{
			if (!pb.ft_add(&i, &nb_contact))
				return (2);
		}
		else if (line == "SEARCH")
		{
			if (!pb.ft_search(nb_contact))
				return (2);
		}
		else if (line == "EXIT")
			exit (0);
	}
	return (0);
}

