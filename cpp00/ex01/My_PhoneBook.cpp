# include "PhoneBook.class.hpp"

bool	ft_atoi(const char *str, int *res)
{
	int	i = 0;
	int	signe = 1;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((*res > INT_MAX / 10 || (*res == INT_MAX / 10 && (str[i] - 48) > INT_MAX % 10)) ||
			(*res < INT_MIN / 10 || (*res == INT_MIN / 10 && (str[i] - 48) > INT_MIN % 10)))
			
			return (false);
	}
}

int	ft_get_line(std::string *line)
{
	std::string	get_line;

	if (std::getline(std::cin, get_line))
	{
		if (std::cin.fail() || std::cin.eof())
		{
			std::cerr << "Error with input data" << std::endl;
			std::cin.clear();
			return (0);
		}
		*line = get_line;
		return (1);
	}
	return (0);
}

int	ft_add(PhoneBook *pb, int *i, int *nb_contact)
{
	std::string	line2;
	const char*	tab[] = {
		"First Name: ",
		"Last Name: ",
		"Nickname: ",
		"Phone Number: ",
		"Darkest Secret"
	};
	int	j = 0;

	std::cout << tab[j++] << std::endl;
	if (ft_get_line(&line2))
		pb->set_contact_first_name(*i, line2);
	else
		return (0);
	std::cout << tab[j++] << std::endl;
	if (ft_get_line(&line2))
		pb->set_contact_last_name(*i, line2);
	else
		return (0);
	std::cout << tab[j++] << std::endl;
	if (ft_get_line(&line2))
		pb->set_contact_nickname(*i, line2);
	else
		return (0);
	std::cout << tab[j++] << std::endl;
	if (ft_get_line(&line2))
		pb->set_contact_phone_number(*i, line2);
	else
		return (0);
	std::cout << tab[j] << std::endl;
	if (ft_get_line(&line2))
		pb->set_contact_darkest_secret(*i, line2);
	else
		return (0);
	(*i)++;
	if (*nb_contact < 8)
		(*nb_contact)++;
	if ((*i) > 7)
		*i = 0;
	return (1);
}

void	ft_get_contact_data(PhoneBook pb, int i)
{
	// recuperer les donnees
	std::string	tab[4][1] = {
		{pb.get_contact_first_name(i)},
		{pb.get_contact_last_name(i)},
		{pb.get_contact_nickname(i)},
		{pb.get_contact_phone_number(i)}
	};
	// trunc la donnee avec un point au 10eme char si elle fait plus de 10 char
	for (int i = 0; i < 4; i++)
	{
		if (tab[i]->length() > 10)
			tab[i][0] = tab[i]->substr(0, 9) + ".";
	}
	// afficher
		// faire une boucle
	std::cout << ANSI_COLOR_YELLOW << "Contact data:" << ANSI_COLOR_RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << tab[i][0];
		if (i < 3)
			std::cout << " | ";
		else
			std::cout << std::endl;
	}
	return ;
}

int	ft_search(PhoneBook pb, int nb_contact)
{
	std::string	line3;
	int			Contact_to_search = 0;

	if (nb_contact == 0)
		return (std::cout << "There is no contact in Phone Book" << std::endl, 1);
	std::cout << "Contact Number to search (0 - 7): " << std::endl;
	if (!ft_get_line(&line3))
		return (0);
	if (!ft_atoi(line3.c_str(), &Contact_to_search))
	{
		std::cout << "Overflow" << std::endl;
		return (0);
	}
	else if (Contact_to_search > 7 || Contact_to_search < 0)
	{
		std::cout << "I Said 0 - 7 not " << Contact_to_search << std::endl;
	}
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
		if (!ft_get_line(&line))
			return (0);
		if (line == "ADD")
		{
			if (!ft_add(&pb, &i, &nb_contact))
			{
				std::cout << "eof" << std::endl;
				return (2);
			}
		}
		else if (line == "SEARCH")
		{
			if (!ft_search(pb, nb_contact))
				return (2);
		}

	}
	return (0);
}

