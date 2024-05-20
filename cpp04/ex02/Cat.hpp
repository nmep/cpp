# ifndef	__CAT_HPP__
	# define	__CAT_HPP__

	# include "Animal.hpp"
	# include "Brain.hpp"

	class Cat : public AAnimal
	{
		private:
			Brain *brain;

		public:
			Cat( void );
			Cat( const std::string type );
			Cat( Cat& copy );
			~Cat();

			Cat&	operator=( Cat& rhs );
			std::string	getType( void ) const;
			void	makeSound( void ) const;
			void	setIdea( const std::string idea );
	};
# endif