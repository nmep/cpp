#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string const type);
		~Weapon(void);

		std::string&	getType(void);
		void			setType(std::string const type);
};

# endif