# ifndef PMERGEME_HPP
	# define PMERGEME_HPP
	# include <iostream>
	# include <deque>
	# include <exception>
	# include <limits.h>
	# include <vector>
	# include <iterator> 
	# include <algorithm>
	# include <ctime>
	# include <iomanip>
	# include <cassert>

	# define RED "\033[31m"
	# define RESET "\033[0m"

	// tools
	unsigned long long ft_atoull(std::string & str);

	// init

	typedef std::deque<unsigned long long>::iterator d_it;
	typedef std::vector<unsigned long long>::iterator v_it;

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
		for (/**/; it != ite; ++it)
		{
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}


	// FJ for deque
	void	ft_merge_sort_max_element_deque(std::deque<unsigned long long> *d, d_it start, d_it end, std::deque<unsigned long long> *max_elements);
	bool	ft_binary_search_insertion_elements_deque(std::deque<unsigned long long> *me, unsigned long long val, int median);
	void	ft_insert_in_max_elements_deque(std::deque<unsigned long long> *d, std::deque<unsigned long long> *max_elements);

	void	ft_FordJohnsonDeque(std::deque<unsigned long long> *d);

	// FJ for vector
	void	ft_merge_sort_max_element_vector(std::vector<unsigned long long> *v, v_it start, v_it end, std::vector<unsigned long long> *max_elements);
	bool	ft_binary_search_insertion_elements_vector(std::vector<unsigned long long> *me, unsigned long long val, int median);
	void	ft_insert_in_max_elements_vector(std::vector<unsigned long long> *v, std::vector<unsigned long long> *max_elements);

	void	ft_FordJohnsonvector(std::vector<unsigned long long> *v);
# endif