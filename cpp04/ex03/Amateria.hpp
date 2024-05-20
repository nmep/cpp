# ifndef	__AMATERIA_HPP__
	# define __AMATERIA_HPP__
	
	# include <iostream>

	class AMateria
	{
		protected:
			const std::string _type;
		public:
			AMateria( void );
			AMateria(std::string const & type);
			~AMateria();
			
			std::string const & getType() const; //Returns the materia type
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
	};

# endif