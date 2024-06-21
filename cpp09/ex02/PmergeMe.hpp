# ifndef PMERGEME_HPP
	# define PMERGEME_HPP
	# include <iostream>
	# include <deque>
	# include <exception>
	# include <limits.h>
	# include <vector>
	# include <iterator> 

	// tools
	unsigned long long ft_atoull(std::string & str);

	// init

	template <typename T>
	int	ft_create_T(T *c, char **av)
	{
		int i = 0;

		while (av[i])
		{
			std::string str(av[i]);
			try
			{
				c->push_back(ft_atoull(str));
			}
			catch (std::invalid_argument& e)
			{
				std::cerr << '[' << av[i] << ']' << " isn't valid: " << e.what() << '\n';
				return 0;
			}
			catch (std::out_of_range& e)
			{
				std::cerr << '[' << av[i] << ']' << " isn't valid: " << e.what() << std::endl;
				return 0;
			}
			i++;
		}
		return 1;
	}

	template <typename T>
	void	ft_print_T(T & c)
	{
		typename T::iterator it = c.begin();
		typename T::iterator ite = c.end();

		if (it == ite)
		{
			std::cout << "empty vector" << std::endl;
			return ;
		}
		std::cout << "---------" << std::endl;
		for (/**/; it != ite; ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
		std::cout << "---------" << std::endl;
	}

	void	ft_FJ_deque(std::deque<unsigned long long> *d);

# endif