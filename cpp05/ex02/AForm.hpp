# ifndef AFORM_HPP
	# define AFORM_HPP
	# include <iostream>
	# include <stdbool.h>
	# include "Bureaucrat.hpp"

	class Bureaucrat;

	class AForm
	{
		private:
			const	std::string	_name;
			bool				_is_signed;
			const int			_grade_to_sign_form;
			const int			_grade_to_execute_form;

		public:
			AForm( void );
			AForm( AForm& copy );
			AForm( const std::string& name, int grade_ts, int grade_te );
			virtual ~AForm();

			void				setIsSigned( bool value );

			const std::string	getName( void ) const;
			bool				getIsSigned( void ) const;
			int 			getGradeToSignForm( void ) const;
			int 			getGradeToExecuteForm( void ) const;

			AForm&				operator=( AForm& other );

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

			virtual void	beSigned( Bureaucrat& frog );
			virtual void	execute(Bureaucrat const & executor) const;
			virtual void	AFormsActions( Bureaucrat const & executor ) = 0;

	};

std::ostream& operator<<(std::ostream& out, AForm& Aform);

# endif