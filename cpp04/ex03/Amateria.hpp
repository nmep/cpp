# ifndef	__AMATERIA_HPP__
	# define __AMATERIA_HPP__

	# include "ICharacter.hpp"

	class AMateria
	{
		protected:
			std::string _type;
		public:
			AMateria( void );
			AMateria(std::string const & type);
			virtual ~AMateria();
			AMateria&	operator=(AMateria& rhs);

			std::string const & getType() const; //Returns the materia type
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
	};

# endif