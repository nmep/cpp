# ifndef	__AAnimal_HPP__
	# define	__AAnimal_HPP__

	# include <iostream>

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
			virtual void	makeSound( void ) const;
	};

# endif