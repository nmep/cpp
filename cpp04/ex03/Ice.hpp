# ifndef	__ICE_HPP__
	# define	__ICE_HPP__

	# include "Amateria.hpp"

	class Ice : public AMateria
	{
		public:
			Ice( void );
			Ice( const Ice& copy );
			~Ice();
			Ice&	operator=( const Ice& rhs );
			virtual Ice* clone( void ) const;

			virtual void use(ICharacter& target);
	};

# endif