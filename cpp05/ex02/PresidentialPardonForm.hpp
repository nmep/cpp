# ifndef PRESIDENTIALPARDONFORM_HPP
	# define PRESIDENTIALPARDONFORM_HPP

	# include "AForm.hpp"

	class PresedientialPardonForm : public AForm
	{
		public:
			PresedientialPardonForm( void );
			PresedientialPardonForm( const std::string &target );
			PresedientialPardonForm( PresedientialPardonForm& copy );
			~PresedientialPardonForm();

			PresedientialPardonForm& operator=( PresedientialPardonForm& rhs );
			void	PresidentialApology( void ) const;
			void	AFormsActions( Bureaucrat const & executor );

	};

std::ostream& operator<<(std::ostream& o, PresedientialPardonForm& other );

# endif