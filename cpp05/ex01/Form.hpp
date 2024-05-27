# ifndef FORM_HPP
	# define FORM_HPP
	# include <iostream>
	# include <stdbool.h>
	# include "Bureaucrat.hpp"

	class Bureaucrate;

	class Form
	{
		private:
			const	std::string	_name;
			bool				_is_signed;
			const int			_grade_to_sign_form;
			const int			_grade_to_execute_form;
		public:
			Form( void );
			Form( Form& copy );
			Form( const std::string& name, int grade_ts, int grade_te );
			~Form();

			void				setIsSigned( bool value );

			const std::string	getName( void ) const;
			bool				getIsSigned( void ) const;
			int 			getGradeToSignForm( void ) const;
			int 			getGradeToExecuteForm( void ) const;

			Form&				operator=( Form& other );

			// void				beSigned( Bureaucrat& frog );

			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char *what(void) const throw();
			};
			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char *what(void) const throw();
			};
			
			void	beSigned( Bureaucrat& frog );
	};

std::ostream& operator<<(std::ostream& out, Form& form);

# endif