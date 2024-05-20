# ifndef	__WRONG_AAnimal_HPP__

	# define	__WRONG_AAnimal_HPP__

	# include "iostream"
	# include "Brain.hpp"

	class WrongAnimal
	{
		protected:
			std::string _type;

		public:
			WrongAnimal( void );
			WrongAnimal( const std::string type);
			WrongAnimal(WrongAnimal& copy);
			virtual ~WrongAnimal();
			std::string getType( void ) const;
			WrongAnimal&	operator=(WrongAnimal& rhs);

			void	makeSound( void ) const;
	};

# endif