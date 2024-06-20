# include "PmergeMe.hpp"

unsigned long long	ft_atoull(std::string & str)
{
	int	i = 0;
	unsigned long long res = 0;
	if (str.size() == 0)
		throw std::invalid_argument("Empty argument");
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			throw std::invalid_argument("Only positive integer");
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > ULLONG_MAX / 10) 
			|| (res == ULLONG_MAX / 10 && (str[i] - 48) >  static_cast<int>(ULLONG_MAX % 10)))
			throw std::out_of_range("Overflow");
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		throw std::invalid_argument(std::string(1, str[i]) + " invalid argument");
	return res;
}

int	ft_create_list(std::list<unsigned long long> *l, char **av)
{
	int i = 0;

	while (av[i])
	{
		std::string str(av[i]);
		try
		{
			(*l).push_back(ft_atoull(str));
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << '[' << av[i] << ']' << " isn't valid: " << e.what() << '\n';
			return 0;
		}
		catch (std::out_of_range& e)
		{
			std::cerr << '[' << av[i] << ']' << " isn't valid: " << e.what() << std::endl;
			return 0;
		}
		i++;
	}
	return 1;
}

void	ft_print_list(std::list<unsigned long long> & l)
{
	std::list<unsigned long long>::iterator it = l.begin();
	std::list<unsigned long long>::iterator ite = l.end();

	if (it == ite)
	{
		std::cout << "empty list" << std::endl;
		return ;
	}
	std::cout << "---------" << std::endl;
	for (/**/; it != ite; ++it)
	{
		std::cout << "la" << std::endl;
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
	std::cout << "---------" << std::endl;
}


int	ft_create_vector(std::vector<unsigned long long> *v, char **av)
{
	int i = 0;

	while (av[i])
	{
		std::string str(av[i]);
		try
		{
			(*v).push_back(ft_atoull(str));
		}
		catch (std::invalid_argument& e)
		{
			std::cerr << '[' << av[i] << ']' << " isn't valid: " << e.what() << '\n';
			return 0;
		}
		catch (std::out_of_range& e)
		{
			std::cerr << '[' << av[i] << ']' << " isn't valid: " << e.what() << std::endl;
			return 0;
		}
		i++;
	}
	return 1;
}

void	ft_print_vector(std::vector<unsigned long long> & v)
{
	std::vector<unsigned long long>::iterator it = v.begin();
	std::vector<unsigned long long>::iterator ite = v.end();

	if (it == ite)
	{
		std::cout << "empty vector" << std::endl;
		return ;
	}
	std::cout << "---------" << std::endl;
	for (/**/; it != ite; ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
	std::cout << "---------" << std::endl;
}

void	ft_list_MJ(std::list<unsigned long long> & l, int segment_size)
{
	std::list<unsigned long long>::iterator it = l.begin();
	std::list<unsigned long long> left;
	std::list<unsigned long long> right;

	left.splice(-)
 	return ;
}