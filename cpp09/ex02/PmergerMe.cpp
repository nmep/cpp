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

	std::cout << "nouvelle list" << std::endl;
	ft_print_T(start, end);
	if (range > 2)
	{
		d_it median = start + range / 2;
		if (range == 3)
		{
			std::cout << "median++" << std::endl;
			median++;
		}
		ft_FJ_deque(d, start, median, max_elements);
		ft_FJ_deque(d, median, end, max_elements);
	}

	if (range == 2)
	{
		std::cout << "start = " << *start << " end = " << *(end - 1) << std::endl;
		if (*start > *(end - 1))
		{
			// max_elements->push_front(*start); // insert recursive
			ft_merge_max_elements(max_elements, *start, static_cast<int>(max_elements->size() / 2));
			d->erase(start);
			std::cout << "plus grand" << std::endl;
		}
		else
		{
			// max_elements->push_front(*(end - 1)); // insert recursive
			ft_merge_max_elements(max_elements, *(end - 1), static_cast<int>(max_elements->size() / 2));
			d->erase(end - 1);
			std::cout << "plus petit" << std::endl;

		}
	}
}

void	ft_merge_max_elements(std::deque<unsigned long long> *me, unsigned long long val, int median)
{
	// creer une partie left et right de me
	std::deque<unsigned long long> left;
	std::deque<unsigned long long> right;

	if (me->empty())
	{
		std::cout << "free insert" << std::endl;
		me->push_back(val);
		return ;
	}
	std::cout << "nouvelle appel" << std::endl;
	left.insert(left.begin(), me->begin(), me->begin() + median);
	right.insert(right.begin(), me->begin() + median, me->end());
	std::cout << "left" << std::endl;
	ft_print_T(left.begin(), left.end());
	std::cout << "right" << std::endl;
	ft_print_T(right.begin(), right.end());
	std::cout << "value = " << val << std::endl;
	// repeter jusqua ce que la taille soit de 1
	if (me->size() > 1)
	{
		// comparer a la valeur median si elle est supp ou inf
		std::cout << "recursive check " << val << " > " << *(me->begin() + median) << " ?" << std::endl;
		if (val > *(me->begin() + median))
		{
			// si elle est supp refaire avec la median right
			std::cout << "recursive avec right" << std::endl;
			ft_merge_max_elements(&right, val, me->size() / 2);

		}
		// sinon avec la median left
		else
		{
			std::cout << "recursive avec left" << std::endl;
			ft_merge_max_elements(&left, val, me->size() / 2);
		}
	}
	std::cout << "median d'insertion = " << median << std::endl;
	std::cout << val << " > " << *(me->begin()) << " ?" << std::endl;
	std::cout << "me" << std::endl;
	ft_print_T(me->begin(), me->end());
	if (val > *(me->begin()))
	{
		std::cout << "push back" << std::endl;
		me->push_back(val);
	}
		// me->insert(me->begin() + median, val);
	else
	{
		std::cout << "push front" << std::endl;
		me->push_front(val);
	}
	std::cout << "max elements trie" << std::endl;
	ft_print_T(me->begin(), me->end());
}