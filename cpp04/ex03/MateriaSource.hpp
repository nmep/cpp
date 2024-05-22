# ifndef	__MATERIASOURCE_HPP__
	# define	__MATERIASOURCE_HPP__
	# include "IMateriaSource.hpp"
	# include "Amateria.hpp"

	class MateriaSource : public IMateriaSource
	{
		private:
			AMateria*	_amateria_source[4];
			std::string	_type;
		public:
			MateriaSource( void );
			MateriaSource( MateriaSource& copy );
			~MateriaSource();
			MateriaSource&	operator=( MateriaSource& rhs );

			void learnMateria( AMateria* learn );
			AMateria* createMateria( std::string const & type );

	};

# endif