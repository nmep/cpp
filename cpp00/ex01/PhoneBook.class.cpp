# include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << ANSI_COLOR_BLUE << "Phone book constructor" << ANSI_COLOR_RESET << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << ANSI_COLOR_RED << "Phone Book destructor" << ANSI_COLOR_RESET << std::endl;
}

// Setters
void	PhoneBook::set_contact_first_name(int index, std::string line) {
	PhoneBook::Object_Contact[index].set_first_name(line);
	return ;
}

void	PhoneBook::set_contact_last_name(int index, std::string line) {
	PhoneBook::Object_Contact[index].set_last_name(line);
	return ;
}

void	PhoneBook::set_contact_nickname(int index, std::string line) {
	PhoneBook::Object_Contact[index].set_nickname(line);
	return ;
}

void	PhoneBook::set_contact_phone_number(int index, std::string line) {
	PhoneBook::Object_Contact[index].set_phone_number(line);
	return ;
}
void	PhoneBook::set_contact_darkest_secret(int index, std::string line) {
	PhoneBook::Object_Contact[index].set_darkest_secret(line);
	return ;
}

// Getters
std::string	PhoneBook::get_contact_first_name(int index) const {
	return (PhoneBook::Object_Contact[index].get_first_name());
	// return ;
}

std::string	PhoneBook::get_contact_last_name(int index) const {
	return PhoneBook::Object_Contact[index].get_last_name();
}

std::string	PhoneBook::get_contact_nickname(int index) const {
	return (PhoneBook::Object_Contact[index].get_nickname());
}

std::string	PhoneBook::get_contact_phone_number(int index) const {
	return (PhoneBook::Object_Contact[index].get_phone_number());
}

std::string	PhoneBook::get_contact_darkest_secret(int index) const {
	return (PhoneBook::Object_Contact[index].get_darkest_secret());
}

// ----------------------------------------------------------------- //
// Methode

bool	PhoneBook::ft_atoi(const char *str, int *res)
{
	int	i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			std::cerr << "Negatif" << std::endl;
			return (false);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((*res > INT_MAX / 10 || (*res == INT_MAX / 10 && (str[i] - 48) > INT_MAX % 10)) ||
			(*res < INT_MIN / 10 || (*res == INT_MIN / 10 && (str[i] - 48) > INT_MIN % 10)))
		{
			std::cerr << "Overflow" << std::endl;
			return (false);
		}		
		*res = *res * 10 + (str[i] - 48);
		i++;
	}
	return (true);
}

int	PhoneBook::ft_get_line(std::string *line)
{
	std::string	get_line;

	if (std::getline(std::cin, get_line))
	{
		*line = get_line;
		return (1);
	}
	else
	{
		if (std::cin.fail() || std::cin.eof())
		{
			std::cout << "Error with input data" << std::endl;
			std::cin.clear();
			return (0);
		}
	}
	return (0);
}

int	PhoneBook::ft_check_line(std::string line)
{
	if (line.find("\x1b[A") <= line.length() || line.find("\x1b[B") <= line.length() || 
		line.find("\x1b[C") <= line.length() || line.find("\x1b[D") <= line.length() 
		|| line.find("\t") <= line.length())
		{
			std::cerr << ANSI_COLOR_CYAN << "Escape code and tab not accepted" << ANSI_COLOR_RESET << std::endl;
			return (0);
		}
	return (1);
}

int	PhoneBook::ft_add(int *i, int *nb_contact)
{
	std::string	line2;
	const char*	tab[] = {
		"First Name: ",
		"Last Name: ",
		"Nickname: ",
		"Phone Number: ",
		"Darkest Secret: "
	};
	int	j = 0;

	std::cout << tab[j++] << std::endl;
	std::cout << "$> ";
	if (ft_get_line(&line2))
	{
		if (!ft_check_line(line2))
			return (1);
		this->set_contact_first_name(*i, line2);
	}
	else
	{
		std::cerr << "Error with getline" << std::endl;
		return (0);
	}
	std::cout << tab[j++] << std::endl;
	std::cout << "$> ";
	if (ft_get_line(&line2))
	{
		if (!ft_check_line(line2))
			return (1);
		this->set_contact_last_name(*i, line2);
	}
	else
	{
		std::cerr << "Error with getline" << std::endl;
		return (0);
	}
	std::cout << tab[j++] << std::endl;
	std::cout << "$> ";
	if (ft_get_line(&line2))
	{
		if (!ft_check_line(line2))
			return (1);
		this->set_contact_nickname(*i, line2);
	}
	else
	{
		std::cerr << "Error with getline" << std::endl;
		return (0);
	}
	std::cout << tab[j++] << std::endl;
	std::cout << "$> ";
	if (ft_get_line(&line2))
	{
		if (!ft_check_line(line2))
			return (1);
		this->set_contact_phone_number(*i, line2);
	}
	else
	{
		std::cerr << "Error with getline" << std::endl;
		return (0);
	}
	std::cout << tab[j] << std::endl;
	std::cout << "$> ";
	if (ft_get_line(&line2))
	{
		if (!ft_check_line(line2))
			return (1);
		this->set_contact_darkest_secret(*i, line2);
	}
	else
	{
		std::cerr << "Error with getline" << std::endl;
		return (0);
	}
	(*i)++;
	if (*nb_contact < 8)
		(*nb_contact)++;
	if ((*i) > 7)
		*i = 0;
	return (1);
}

void	PhoneBook::ft_get_contact_data(int i)
{
	// recuperer les donnees
	std::string	tab[5][1] = {
		{this->get_contact_first_name(i)},
		{this->get_contact_last_name(i)},
		{this->get_contact_nickname(i)},
		{this->get_contact_phone_number(i)},
		{this->get_contact_darkest_secret(i)}
	};
	// trunc la donnee avec un point au 10eme char si elle fait plus de 10 char
	for (int i = 0; i < 5; i++)
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

int	PhoneBook::ft_is_num(const char *str)
{
	int	i = 0;
	int	flag = 0;
	while (str[i])
	{
		if ((str[i] != '-' || str[i] != '+') && (str[i] < '0' || str[i] > '9'))
		{
			std::cerr << ANSI_COLOR_MAGENT << "Alpha numeric pls (- and + is accepted)" << ANSI_COLOR_RESET << std::endl;
			return (0);
		}
		if ((str[i] >= '0' && str[i] <= '9') && flag <= INT_MAX)
			flag++;
		i++;
	}
	if (flag == 0)
	{
		std::cerr << ANSI_COLOR_MAGENT << "Give me an integer" << ANSI_COLOR_RESET << std::endl;
		return (0);
	}
	return (1);
}

int	PhoneBook::ft_search(int nb_contact)
{
	std::string	line3;
	int			Contact_to_search = 0;
	int			attempts = 0;

	if (nb_contact == 0)
		return (std::cout << "There is no contact in Phone Book" << std::endl, 1);

	for (int i = 0; i < nb_contact; i++)
	{
		std::cout << (i + 1) << " | ";
		std::cout << get_contact_first_name(i) << " | ";
		std::cout << get_contact_last_name(i) << " | ";
		std::cout << get_contact_nickname(i) << " | ";
		std::cout << get_contact_phone_number(i) << std::endl;
	}

	std::cout << "Contact Number to search (1 - 8): " << std::endl;
	while (true)
	{
		if (!ft_get_line(&line3))
			return (0);
		attempts++;
		if (!ft_check_line(line3))
		{
			if (attempts > 3)
				return (1);
			std::cout << ANSI_COLOR_RED << (3 - attempts) + 1 << " try left check line" << ANSI_COLOR_RESET << std::endl;
			continue ;
		}

		if (!ft_is_num(line3.c_str()))
		{
			if (attempts > 3)
				return (1);
			std::cout << ANSI_COLOR_RED << (3 - attempts) + 1 << " try left is num" << ANSI_COLOR_RESET << std::endl;;
			continue;
		}
		break ;
	}

	if (!ft_atoi(line3.c_str(), &Contact_to_search))
		return (1);
	if (Contact_to_search > 8 || Contact_to_search < 1)
	{
		std::cout << ANSI_COLOR_GREEN << "I Said 1 - 8 not: " << Contact_to_search << ANSI_COLOR_RESET << std::endl;
		return (1);
	}

	if (Contact_to_search <= nb_contact)
		ft_get_contact_data(Contact_to_search - 1);
	else
		std::cerr << ANSI_COLOR_RED << "there is not " << Contact_to_search << " Contact max " << nb_contact << std::endl;
	return (1);
}