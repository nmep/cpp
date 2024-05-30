# ifndef INTERN_HPP
	# define INTERN_HPP

	# include "AForm.hpp"
	# include "RobotomyRequestForm.hpp"
	# include "PresidentialPardonForm.hpp"
	# include "ShrubberyCreationForm.hpp"

	class Intern
	{
		private:

		public:
			Intern( void );
			~Intern();
			Intern& operator=(Intern& rhs );
			std::string	strToLower( const std::string& str );

			AForm* makeForm( const std::string& formName, const std::string& target );
	};

# endif