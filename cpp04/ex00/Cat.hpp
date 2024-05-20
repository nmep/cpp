# ifndef	__CAT_HPP__
	# define	__CAT_HPP__

	# include "AAnimal.hpp"

	class Cat : public AAnimal
	{
		public:
			Cat( void );
			Cat( const std::string type );
			Cat( Cat& copy );
			~Cat();

			Cat&	operator=( Cat& rhs );
			std::string	getType( void ) const;
			void	makeSound( void ) const;
	};
# endif