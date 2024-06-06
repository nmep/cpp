# include <iostream>
# include <cstdlib>
# include <ctime>
# include <exception>

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base*	generate( void )
{
	srand(time(0));

	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			break;
	}
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identify by pointer: the type of " << p << " is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identify by pointer: the type of " << p << " is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identify by pointer: the type of " << p << " is C" << std::endl;
	else
		std::cout << "Identify by pointer: invalid address" << std::endl;
}

void	indentify(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "Identify by reference: the type of " << &p << " is A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "Identify by reference: the type of " << &p << " is B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "Identify by reference: the type of " << &p << " is C" << std::endl;
	else
		std::cout << "Identify by reference: Invalid address" << std::endl;
}

int	main()
{
	Base *Aptr = generate();

	std::cout << "POINTERS" << std::endl;

	identify(Aptr);
	delete Aptr;
	identify(NULL);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "REFERENCES" << std::endl;

	Base & InvalidReference = *new Base();
	indentify(InvalidReference);
	delete &InvalidReference;

	Base & CReference = *new C();
	indentify(CReference);
	delete &CReference;
}