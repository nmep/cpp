# ifndef __CHARACTER_HPP__
	# define	__CHARACTER_HPP__

	# include "ICharacter.hpp"
	# include "AMateria.hpp"

	class Character : public ICharacter
	{
		private:
			static const int	_inventory_size = 4;
			AMateria	*_inventory[_inventory_size];
			std::string _name;
			//
		public:
			Character( void );
			Character(const std::string & name);
			Character( Character& copy );
			Character&	operator=( Character& rhs );
			~Character();
			std::string const & getName() const;
			void	equip(AMateria* m);
			void	unequip(int idx);
			void	use(int idx, ICharacter& target);
			//
	};

# endif