// # ifndef	__ICHARACTER_HPP__
// 	# define	__ICHARACTER_HPP__

// 	# include <iostream>
// 	# include "Amateria.hpp"

// class Amateria;

// 	class ICharacter
// 	{
// 		public:
// 			virtual ~ICharacter() {}
// 			virtual std::string const & getName() const = 0;
// 			virtual void equip(AMateria* m) = 0;
// 			virtual void unequip(int idx) = 0;
// 			virtual void use(int idx, ICharacter& target) = 0;
// 	};
// # endif

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

	# include "AMateria.hpp"
	# include <iostream>
	class AMateria;

	class ICharacter
	{
		public:
			virtual ~ICharacter() {}
			virtual std::string const & getName() const = 0;
			virtual void equip(AMateria *m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
		protected:
			const std::string _name;
	};

#endif