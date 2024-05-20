# ifndef	__DOG_HPP__
	# define	__DOG_HPP__

	# include "AAnimal.hpp"

	class Dog : public AAnimal
	{
		public:
			Dog( void );
			Dog( const std::string type );
			Dog( Dog& copy );
			~Dog();

			std::string getType( void ) const;
			Dog& operator=(Dog& rhs);

			void makeSound( void ) const;
	};

# endif