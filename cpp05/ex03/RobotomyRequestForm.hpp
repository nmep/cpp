# ifndef ROBOTMYREQUESTFORM_HPP
	# define ROBOTMYREQUESTFORM_HPP

	# include "AForm.hpp"
	# include <unistd.h>

	class RobotMyRequestForm : public AForm
	{
		public:
			RobotMyRequestForm( void );
			RobotMyRequestForm( const std::string& target );
			~RobotMyRequestForm();

			void	Robotomized( void );
			void	AFormsActions( Bureaucrat const & executor );
	};

std::ostream& operator<<(std::ostream& o, RobotMyRequestForm& other );

# endif