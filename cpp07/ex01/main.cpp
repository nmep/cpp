# include "iter.hpp"

int	main()
{
	std::string array = "bonjour";
	int  integ_array[] = {1, 2, 3, 4, 5};

	iter(array.c_str(), array.size(), ft_putstr<const char>);

	iter(integ_array, static_cast<unsigned int>(5), ft_putstr<const int>);

}