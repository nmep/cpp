# ifndef SHRUBBERYCREATIONFORM_HPP
	# define SHRUBBERYCREATIONFORM_HPP

	# include "AForm.hpp"
	# include "fstream"

	class ShrubberyCreationForm : public AForm
	{
		public:
		// canonic
			ShrubberyCreationForm( void );
			ShrubberyCreationForm( const std::string& target );
			~ShrubberyCreationForm();

			void Create_tree( void );
			void	AFormsActions( Bureaucrat const & executor );
	};

std::ostream& operator<<( std::ostream& o, ShrubberyCreationForm& other );

# endif