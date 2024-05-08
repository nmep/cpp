#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		Weapon&	_Weapon;
		std::string _name;
	public:
		HumanA(std::string name, Weapon& rand_Weapon);
		~HumanA(void);

		void	attack(void) const;
};

# endif