# ifndef PhoneBook_H
# define PhoneBook_H

# include <iostream>
# include <string>
# include <string.h>
# include "Contact.class.hpp"

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
	void	get_contact_first_name(int index) const {
		Object_Contact[index].get_first_name();
		return ;
	}

	void	get_contact_last_name(int index) const {
		Object_Contact[index].get_last_name();
		return ;
	}

	void	get_contact_nickname(int index) const {
		Object_Contact[index].get_nickname();
		return ;
	}

	void	get_contact_phone_number(int index) const {
		Object_Contact[index].get_phone_number();
		return ;
	}

	void	get_contact_darkest_secret(int index) const {
		Object_Contact[index].get_darkest_secret();
		return ;
	}

};

# endif