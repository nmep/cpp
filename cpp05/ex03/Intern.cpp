# include "Intern.hpp"

Intern::Intern( void ) {}

Intern::~Intern() {}

Intern&	Intern::operator=( Intern& rhs )
{
	(void)rhs;
	return *this;
}

std::string	Intern::strToLower( const std::string& str )
{
	std::string	res;

	for (unsigned int i = 0; i < str.length(); i++)
		res += tolower(str[i]);
	return res;
}

// typedef AForm *(*FormConstructorPtr)(const std::string);

AForm*	newRobot( const std::string& target)
{
	return new RobotMyRequestForm(target);
}

AForm*	newPresident( const std::string& target )
{
	return new PresedientialPardonForm(target);
}

AForm*	newShrubbery( const std::string& target )
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm( const std::string& formName, const std::string& target )
{
	AForm	*formPtr = NULL;
	std::string	formNameLower = strToLower(formName);
	AForm* (*formPtrArray[3])( const std::string& ) = { &newRobot, &newPresident, &newShrubbery};

	std::string formTab[3] = {"robotomyrequest", "presidentpardon", "shrubberycreation"};

	for (int i = 0; i < 3; i++)
	{
		if (formTab[i] == formNameLower)
		{
			formPtr = (*formPtrArray[i])(target);
			std::cout << "Inter creates " << formName << std::endl;
			return formPtr;
		}
	}
	std::cout << "Form not found in whatever look likes to a dats base" << std::endl;
	return (formPtr);
}