# ifndef __CHARACTER_HPP__
	# define	__CHARACTER_HPP__

	# include "ICharacter.hpp"

	class Character : public ICharacter
	{
		private:
			static const int	_inventory_size = 4;
			AMateria	*_inventory[_inventory_size];
			std::string _name;
			//
		public:
			Character( void );
			Character( Character& copy );
			Character&	operator=( Character& rhs );
			~Character();
			std::string const & getName() const override;
			void	equip(AMateria* m) override;
			void	unequip(int idx) override;
			void	use(int idx, ICharacter& target) override;
			//
	};

# endif