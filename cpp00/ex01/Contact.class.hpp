# ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

#define ANSI_COLOR_RED		"\033[1;31m"
#define ANSI_COLOR_GREEN	"\033[1;32m"
#define ANSI_COLOR_YELLOW	"\033[1;33m"
#define ANSI_COLOR_BLUE		"\033[1;34m"
#define ANSI_COLOR_MAGENT	"\033[1;35m"
#define ANSI_COLOR_CYAN		"\033[1;36m"
#define ANSI_COLOR_WHITE	"\033[1;37m"
#define ANSI_COLOR_RESET	"\033[0m"

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

	public:
		// C / D
		Contact(void);
		~Contact(void);
		// setteur
		void	set_first_name(std::string line) {
			_first_name = line;
			return ;
		}

		void	set_last_name(std::string line) {
			_last_name = line;
			return ;
		}

		void	set_nickname(std::string line) {
			_nickname = line;
			return ;
		}

		void	set_phone_number(std::string line) {
			_phone_number = line;
			return ;
		}

		void	set_darkest_secret(std::string line) {
			_darkest_secret = line;
			return ;
		}

		// getteur
		std::string	get_first_name(void) const {
			return _first_name;
		}

		std::string	get_last_name(void) const {
			return _last_name;
		}

		std::string	get_nickname(void) const {
			return _nickname;
		}

		std::string	get_phone_number(void) const {
			return _phone_number;
		}

		std::string	get_darkest_secret(void) const {
			return _darkest_secret;
		}
};

# endif