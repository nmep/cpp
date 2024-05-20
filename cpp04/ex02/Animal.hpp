# ifndef	__Animal_HPP__
	# define	__Animal_HPP__

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


	class AAnimal
	{
		protected:
			std::string _type;
		public:
			AAnimal( void );
			AAnimal( const std::string name );
			virtual ~AAnimal();

			AAnimal& operator=(AAnimal& other);
			std::string	getType( void ) const;
			virtual void	makeSound( void ) const = 0;
	};

# endif