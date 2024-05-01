# ifndef PhoneBook_H
# define PhoneBook_H

# include <iostream>
# include <string>
# include <string.h>
# include <cstdlib>
# include "Contact.class.hpp"
# include <limits.h>
# include <stdbool.h>

class PhoneBook
{
	private:
		Contact Object_Contact[8];

	public:
		PhoneBook(void);
		~PhoneBook(void);
	// Setters
	void	set_contact_first_name(int index, std::string line) {
		Object_Contact[index].set_first_name(line);
		return ;
	}

	void	set_contact_last_name(int index, std::string line) {
		Object_Contact[index].set_last_name(line);
		return ;
	}

	void	set_contact_nickname(int index, std::string line) {
		Object_Contact[index].set_nickname(line);
		return ;
	}

	void	set_contact_phone_number(int index, std::string line) {
		Object_Contact[index].set_phone_number(line);
		return ;
	}
	void	set_contact_darkest_secret(int index, std::string line) {
		Object_Contact[index].set_darkest_secret(line);
		return ;
	}

	// Getters
	std::string	get_contact_first_name(int index) const {
		return (Object_Contact[index].get_first_name());
		// return ;
	}

	std::string	get_contact_last_name(int index) const {
		return Object_Contact[index].get_last_name();
	}

	std::string	get_contact_nickname(int index) const {
		return (Object_Contact[index].get_nickname());
	}

	std::string	get_contact_phone_number(int index) const {
		return (Object_Contact[index].get_phone_number());
	}

	std::string	get_contact_darkest_secret(int index) const {
		return (Object_Contact[index].get_darkest_secret());
	}

};

# endif