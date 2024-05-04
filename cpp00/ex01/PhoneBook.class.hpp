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
	void	set_contact_first_name(int index, std::string line);
	void	set_contact_last_name(int index, std::string line);
	void	set_contact_nickname(int index, std::string line);
	void	set_contact_phone_number(int index, std::string line);
	void	set_contact_darkest_secret(int index, std::string line);

	// Getters
	std::string	get_contact_first_name(int index) const;
	std::string	get_contact_last_name(int index) const;
	std::string	get_contact_nickname(int index) const;
	std::string	get_contact_phone_number(int index) const;
	std::string	get_contact_darkest_secret(int index) const;

	// Methode
	bool	ft_atoi(const char *str, int *res);
	int		ft_get_line(std::string *line);
	int		ft_check_line(std::string line);
	int		ft_add(int *i, int *nb_contact);
	void	ft_get_contact_data(int i, int ds);
	int		ft_is_num(const char *str);
	int		ft_search(int nb_contact);
};

# endif