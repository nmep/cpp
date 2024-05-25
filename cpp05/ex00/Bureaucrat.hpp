# ifndef BUREAUCRAT_HPP
	# define BUREAUCRAT_HPP

	# include <iostream>
	# include <cstdlib>
	# include <stdexcept>

	class Bureaucrat
	{
		private:
			const std::string	_name;
			int					_grade;

		public:
			Bureaucrat( void );
			Bureaucrat( const std::string& name );
			~Bureaucrat();

			const std::string	getName( void ) const;
			int					getGrade( void ) const;
			void				setGrade( const std::string& grade );
			int					atoi( const std::string& str );

	};

# endif
