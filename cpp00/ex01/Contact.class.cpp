# include "Contact.class.hpp"

Contact::Contact(void)
{
	std::cout << ANSI_COLOR_GREEN << "Contact Class Constructor\033[0m" << ANSI_COLOR_RESET << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << ANSI_COLOR_RED << "Contact Class Destructor" << ANSI_COLOR_RESET << std::endl;
	return ;
}
