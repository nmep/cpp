# ifndef	__CURE_HPP__
	# define	__CURE_HPP__

		# include "Amateria.hpp"

	class Cure : public AMateria
	{
		public:
			Cure( void );
			Cure( const Cure& copy );
			~Cure();
			Cure&	operator=( const Cure& rhs );
			virtual Cure* clone( void ) const;

			virtual void use(ICharacter& target);
	};
# endif