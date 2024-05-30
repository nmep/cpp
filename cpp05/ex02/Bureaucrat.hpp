	# ifndef BUREAUCRAT_HPP
		# define BUREAUCRAT_HPP

		# include <iostream>
		# include <cstdlib>
		# include <stdexcept>
		# include <limits.h>
		# include "AForm.hpp"

		class AForm;

		class Bureaucrat
		{
			private:
				const std::string	_name;
				int					_grade;

			public:
				Bureaucrat( void );
				Bureaucrat( const std::string& name );
				Bureaucrat( const std::string& name, const std::string& grade);
				Bureaucrat( Bureaucrat& copy );
				~Bureaucrat();

				const std::string	getName( void ) const;
				int					getGrade( void ) const;
				void				setGrade( const std::string& grade );
				int					ft_atoi( const std::string& str );
				Bureaucrat&			operator=(Bureaucrat& other);

				class GradeTooHighException : public std::exception
				{
					public:
						virtual const char *what( void ) const throw();
				};
				class GradeTooLowException : public std::exception
				{
					public:
						virtual const char *what( void ) const throw();
				};

				void				incrementGrade( void );
				void				decrementGrade( void );
				void				executeForm(AForm const & form);
		};

	std::ostream& operator<<( std::ostream& out, Bureaucrat& frog );

	# endif
