# include "PhoneBook.class.hpp"


int	ft_add(PhoneBook pb)
{
	static int	i = 0;
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
			pb.set_contact_first_name(i, line2);
			// prendre last name
			pb.set_contact_last_name(i, line2);
			// prendre nickname
			pb.set_contact_nickname(i, line2);
			// prendre phone number
			pb.set_contact_phone_number(i, line2);
			// prendre darkest secret
			pb.set_contact_darkest_secret(i, line2);
		}
		else
		{
			std::cerr << "error with input data" << std::endl;
			return (0);
		}
	}
	i++;
	if (i > 7)
		i = 0;
	return (1);
}

int	ft_search(PhoneBook pb)
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
	for (int i = 0; i < 5; i++)
	{
		
	}
	return (1);
}

int	main()
{
	PhoneBook		pb;
	std::string		line;

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
			if (!ft_add(pb))
			{
				std::cout << "eof" << std::endl;
				return (2);
			}
		}
		else if (line == "SEARCH")
		{
			ft_search(pb);
		}
		std::cout << line << std::endl;
	}
	return (0);
}

