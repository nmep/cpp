# include "Serializer.hpp"

int	main()
{
	Data	d;

	d.value = 10;

	std::cout << &d << std::endl;
	std::cout << Serializer::serialize(&d) << std::endl;
	uintptr_t ptt = Serializer::serialize(&d);

	std::cout << Serializer::deserialize(ptt)->value << std::endl;
}