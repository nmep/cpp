# include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage example: ./PmergerMe 15 90 37 1 2 7" << std::endl;
		return 2;
	}
	// else if (ac == 2)
	// {
	// 	std::cerr << "Can't sort one integer" << std::endl;
	// 	return 2;
	// }

	std::deque<unsigned long long> d;
	if (ft_create_T(&d, ++av) == 0)
		return 2;
	std::vector<unsigned long long> v;
	if (ft_create_T(&v, av) == 0)
		return 2;
	std::cout << "BEFORE:\n";
	ft_print_T(d.begin(), d.end());
	std::deque<unsigned long long> max_elements;
	ft_FJ_deque(&d, d.begin(), d.end(), &max_elements);
	std::cout << "AFTER:\n";
	ft_print_T(d.begin(), d.end());
	ft_print_T(max_elements.begin(), max_elements.end());
}