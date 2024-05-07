#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Addresse de la string en memoire " << &str << std::endl;
	std::cout << "Addresse stocke dans stringPTR " << stringPTR << std::endl;
	std::cout << "Addresse stocke dans stringREF " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Valeurs de la string " << str << std::endl;
	std::cout << "Valeurs pointe par stringPTR " << *stringPTR << std::endl;
	std::cout << "Valeurs de la stringREF " << stringREF << std::endl;

}