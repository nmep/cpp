#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

#define ANSI_COLOR_RED		"\033[1;31m"
#define ANSI_COLOR_GREEN	"\033[1;32m"
#define ANSI_COLOR_YELLOW	"\033[1;33m"
#define ANSI_COLOR_BLUE		"\033[1;34m"
#define ANSI_COLOR_MAGENT	"\033[1;35m"
#define ANSI_COLOR_CYAN		"\033[1;36m"
#define ANSI_COLOR_WHITE	"\033[1;37m"
#define ANSI_COLOR_RESET	"\033[0m"

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

# endif