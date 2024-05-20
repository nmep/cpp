# ifndef	__DOG_HPP__
	# define	__DOG_HPP__

	# include "AAnimal.hpp"
	# include "Brain.hpp"

	class Dog : public AAnimal
	{
		private:
			Brain *brain;
		public:
			Dog( void );
			Dog( const std::string type );
			Dog( Dog& copy );
			~Dog();

			std::string getType( void ) const;
			Dog& operator=(Dog& rhs);

			void	makeSound( void ) const;
			void	setIdea( const std::string idea );
	};

# endif