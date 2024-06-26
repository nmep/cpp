# include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage example: ./PmergerMe 15 90 37 1 2 7" << std::endl;
		return 2;
	}

	std::deque<unsigned long long> d;
	if (ft_create_T(&d, ++av) == 0)
		return 2;
	std::vector<unsigned long long> v;
	if (ft_create_T(&v, av) == 0)
		return 2;
// DEQUE
	std::cout << "DEQUE" << std::endl;
	
	std::cout << "BEFORE:\n";
	ft_print_T(d.begin(), d.end());

	ft_FordJohnsonDeque(&d);

	std::cout << "AFTER:\n";
	ft_print_T(d.begin(), d.end());

	std::cout << RED << "VECTOR" << RESET << std::endl;
	
	std::cout << "BEFORE V:\n";
	ft_print_T(v.begin(), v.end());

	ft_FordJohnsonVector(&v);

	std::cout << "AFTER V:\n";
	ft_print_T(v.begin(), v.end());
}