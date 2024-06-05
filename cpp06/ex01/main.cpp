# include "Serializer.hpp"

int	main()
{
	Data	d;

	d.value = 10;
	Serializer p1(&d);

	std::cout << &d << std::endl;
	std::cout << p1.serialize(&d) << std::endl;
	uintptr_t ptt = p1.serialize(&d);

	std::cout << p1.deserialize(ptt)->value << std::endl;
}