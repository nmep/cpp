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
	std::list<unsigned long long> l;
	if (!ft_create_list(&l, ++av))
		return 1;
	std::vector<unsigned long long> v;
	if (!ft_create_vector(&v, av))
		return 1;

	// if (l.size() % 2 != 0)
	// {
	// 	l_last = l.back();
	// 	l.pop_back();
	// 	v_last = v.back();
	// 	v.pop_back();
	// }

	ft_list_MJ(l, l.size() / 2);
}