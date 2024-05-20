# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"
# include "Brain.hpp"

int	main( void )
{
	// ------------------------------

	// AAnimal	a;
	// AAnimal	b("test");
	// Dog		dog;
	// Dog		copyDog(dog);
	// Cat		cat1;

	// std::cout << "a type is " << a.getType() << std::endl;

	// std::cout << "Should be \"AAnimal\" Sound" << std::endl;
	// a.makeSound();

	// std::cout << std::endl;

	// std::cout << "Should be \"test\"" << std::endl;
	// std::cout << "b type is " << b.getType() << std::endl;
	// std::cout << std::endl;
	// a = b;
	// std::cout << "Should be \"test\"" << std::endl;
	// std::cout << "a type is " << a.getType() << std::endl;

	// std::cout << "Dog copy type is " << copyDog.getType() << std::endl;

	// a.makeSound();
	// dog.makeSound();
	// const AAnimal* meta = new AAnimal();
	// const AAnimal* j = new Dog();
	// const AAnimal* i = new Cat();
	// std::cout << "1) " << j->getType() << " " << std::endl;
	// std::cout << "2) " << i->getType() << " " << std::endl;
	// std::cout << "3) ";
	// i->makeSound(); //will output the cat sound!
	// std::cout << "4) ";
	// j->makeSound();
	// std::cout << "5) ";
	// meta->makeSound();
	// std::cout << "6) ";
	// delete meta;
	// std::cout << "7) ";
	// delete j;
	// std::cout << "8) ";
	// delete i;
	// std::cout << std::endl;
	// std::cout << "Wrong" << std::endl;

	// const WrongAnimal* WWC = new WrongCat();
	// std::cout << WWC->getType() << " " << std::endl;
	// WWC->makeSound();
	// delete WWC;
	// ------------------------------

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	// Cat l;

	AAnimal *tab[10];

	std::cout << "allocation of the AAnimal table" << std::endl;
	for(int	i = 0; i < 10; i++)
	{
		if (i < 5)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
	}
	std::cout << "desalocation of space" << std::endl;
	for (int i = 0; i < 10; i++)
		delete tab[i];
	delete j;//should not create a leak
	delete i;
	return 0;
}