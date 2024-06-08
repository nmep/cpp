# include "easyfind.hpp"


int	main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	try
	{
		easyfind(v, 2);
		easyfind(v, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}