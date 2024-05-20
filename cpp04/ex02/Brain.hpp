# ifndef	__BRAIN_HPP__
	# define	__BRAIN_HPP__

	# include <iostream>
	# define RESET   "\033[0m"
	# define BLACK   "\033[30m"
	# define RED     "\033[31m"
	# define GREEN   "\033[32m"
	# define YELLOW  "\033[33m"
	# define BLUE    "\033[34m"
	# define MAGENTA "\033[35m"
	# define CYAN    "\033[36m"
	# define WHITE   "\033[37m"

	class Brain
	{
		private:
			std::string ideas [100];
		public:
			Brain( void );
			Brain( Brain& copy );
			virtual ~Brain();
			Brain&	operator=( Brain& rhs );
			std::string getIdeas( int i ) const;
			void	setIdea(const std::string idea);
			void	ShowIdea( void ) const;
	};

# endif