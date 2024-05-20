# ifndef	__WRONGCAT_HPP__

	# define	__WRONGCAT_HPP__

	# include "iostream"
	# include "WrongAnimal.hpp"

	class WrongCat : public WrongAnimal
	{
		public:
			WrongCat( void );
			WrongCat( const std::string type);
			WrongCat(WrongCat& copy);
			~WrongCat();
			std::string getType( void ) const ;
			WrongCat&	operator=(WrongCat& rhs);

			void	makeSound( void ) const;
	};

# endif