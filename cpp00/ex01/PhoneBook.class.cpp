# include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << ANSI_COLOR_BLUE << "Phone book constructor" << ANSI_COLOR_RESET << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << ANSI_COLOR_RED << "Phone Book destructor" << ANSI_COLOR_RESET << std::endl;
}