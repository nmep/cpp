# include "Array.hpp"

int	main()
{
	Array <int>a;
	Array <unsigned int>b(static_cast<unsigned int>(5));
	std::cout << "b is an empty array of size 5" << std::endl;
	b.display();


	Array<char> c(static_cast<unsigned int>(10));
	c.SetArray(97);
	std::cout << "Object C is now at \'a\' " << std::endl;
	c.display();
	Array<int> copy(c);
	std::cout << "Object C is now at 98 " << std::endl;
	copy.display();
	try
	{
		std::cout << copy[20] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	b = copy;
	std::cout << "b must be 99" << std::endl;
	b.display();
	std::cout << "copy must be 98" << std::endl;
	copy.display();
}