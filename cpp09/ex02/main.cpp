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

	std::cout << "before: ";
	ft_print_T(d.begin(), d.end());
	
	std::clock_t cpu_start_d = std::clock();
	
	ft_FordJohnsonDeque(&d);
	
	double cpu_end_d= (std::clock() - cpu_start_d) * (1.0 / CLOCKS_PER_SEC);

	std::cout << "after: ";
	ft_print_T(d.begin(), d.end());
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << std::fixed << std::setprecision(6) << cpu_end_d << " μs" << std::endl;


	std::clock_t cpu_start_v = std::clock();
	ft_FordJohnsonvector(&v);
	double cpu_end_v = (std::clock() - cpu_start_v) * (1.0 / CLOCKS_PER_SEC);
	std::cout << "Time to process a range of " << d.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << cpu_end_v << " μs" << std::endl;
}