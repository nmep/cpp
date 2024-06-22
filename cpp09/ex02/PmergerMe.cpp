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

void	ft_FJ_deque(std::deque<unsigned long long> *d, d_it start, d_it end, std::deque<unsigned long long> *max_elements)
{
	int range = std::distance(start, end);

	// std::cout << "nouvelle list" << std::endl;
	// ft_print_T(start, end);
	if (range > 2)
	{
		d_it median = start + range / 2;
		if (range == 3)
			median++;
		std::cout << "la median est " << *median << std::endl;
		ft_FJ_deque(d, start, median, max_elements);
		ft_FJ_deque(d, median, end, max_elements);
	}

	if (range == 2)
	{
		if (*start > *(end - 1))
		{
			max_elements->push_front(*start);
			d->erase(start);
		}
		else
		{
			max_elements->push_front(*(end - 1));
			d->erase(end - 1);
		}
	}
	
}

void	ft_merge_max_elements(std::deque<unsigned long long> *me)
{
	std::deque<unsigned long long> left;
	std::deque<unsigned long long> right;
	size_t median = me->size() / 2;
	
	if (me->size() > 1)
	{
		
	}
}