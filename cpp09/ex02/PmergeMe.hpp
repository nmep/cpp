# ifndef PMERGEME_HPP
	# define PMERGEME_HPP
	# include <iostream>
	# include <deque>
	# include <exception>
	# include <limits.h>
	# include <vector>
	# include <iterator> 
	# include <algorithm>

	// tools
	unsigned long long ft_atoull(std::string & str);

	// init

	typedef std::deque<unsigned long long>::iterator d_it;


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

	template<typename Iterator>
	void	ft_print_T(Iterator it, Iterator ite)
	{
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

	void	ft_FJ_deque(std::deque<unsigned long long> *d, d_it start, d_it end, std::deque<unsigned long long> *max_elements);
	void	ft_merge_max_elements(std::deque<unsigned long long> *me);

# endif