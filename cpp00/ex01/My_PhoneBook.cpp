# include "PhoneBook.class.hpp"


int	ft_add(PhoneBook pb, int *i, int *nb_contact)
{
	std::string	line2;
	const char*	tab[] = {
		"First Name: ",
		"Last Name: ",
		"Nickname: ",
		"Phone Number: ",
		"Darkest Secret"
	};

	for (int j = 0; j < 5; j++)
	{
		std::cout << tab[j] << std::endl;

		if (std::getline(std::cin, line2))
		{
			if (std::cin.eof() || std::cin.fail())
			{
				std::cin.clear();
				return (0);
			}
			// prendre first name
			pb.set_contact_first_name(*i, line2);
			// prendre last name
			pb.set_contact_last_name(*i, line2);
			// prendre nickname
			pb.set_contact_nickname(*i, line2);
			// prendre phone number
			pb.set_contact_phone_number(*i, line2);
			// prendre darkest secret
			pb.set_contact_darkest_secret(*i, line2);
		}
		else
		{
			std::cerr << "error with input data" << std::endl;
			return (0);
		}
	}
	i++;
	if (*nb_contact < 8)
		(*nb_contact)++;
	if ((*i) > 7)
		*i = 0;
	return (1);
}

void	ft_get_contact_data(PhoneBook pb, int i)
{
	std::cout << "trouve" << std::endl;
	return ;
}


int	ft_search(PhoneBook pb, int nb_contact)
{
	std::string	line3;
	std::cout << "Contact to search: " << std::endl;
	std::getline(std::cin, line3);
	if (std::cin.eof() || std::cin.fail())
	{
		std::cout << "error with input data" << std::endl;
		std::cin.clear();
		return (0);
	}
	for (int i = 0; i < nb_contact; i++)
	{
		if (pb.get_contact_first_name(i) == line3)
			ft_get_contact_data(pb, i);
		else if (pb.get_contact_last_name(i) == line3)
			ft_get_contact_data(pb, i);
		else if (pb.get_contact_nickname(i) == line3)
			ft_get_contact_data(pb, i);
		else if (pb.get_contact_phone_number(i) == line3)
			ft_get_contact_data(pb, i);
		else if (pb.get_contact_darkest_secret(i) == line3)
			ft_get_contact_data(pb, i);
	}
	if (nb_contact == 0)
		std::cout << "There is no contact in Phone Book" << std::endl;
	return (1);
}

int	main()
{
	PhoneBook		pb;
	std::string		line;
	int				i = 0;
	int				nb_contact = 0;

	while (std::cin)
	{
		std::getline(std::cin, line);
		if (std::cin.eof() || std::cin.fail()) 
		{
			std::cerr << "error with input data" << std::endl;
			std::cin.clear();
			return (2);
		}
		if (line == "ADD")
		{
			if (!ft_add(pb, &i, &nb_contact))
			{
				std::cout << "eof" << std::endl;
				return (2);
			}
		}
		else if (line == "SEARCH")
		{
			ft_search(pb, nb_contact);
		}
		std::cout << line << std::endl;
	}
	return (0);
}

