# ifndef PMERGEME_HPP
	# define PMERGEME_HPP
	# include <iostream>
	# include <list>
	# include <exception>
	# include <limits.h>
	# include <vector>

	// tools
	unsigned long long ft_atoull(std::string & str);
	void	ft_print_list(std::list<unsigned long long> & l);
	void	ft_print_vector(std::vector<unsigned long long> & v);


	// init
	int	ft_create_list(std::list<unsigned long long> *l, char **av);
	int	ft_create_vector(std::vector<unsigned long long> *v, char **av);
	void	ft_list_MJ(std::list<unsigned long long> & l, unsigned long long l_last, int i);


# endif