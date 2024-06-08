# ifndef EASYFIND_HPP
	# define EASYFIND_HPP

	# include <vector>
	# include <algorithm>
	# include <exception>
	# include <iterator>
	# include <iostream>

	template<typename T>
	void	easyfind(T & cont, int n)
	{
		typename T::iterator	it;

		it = std::find(cont.begin(), cont.end(), n);

		if (it == cont.end())
		{
			throw std::exception();
		}
		std::cout << "Occurence found: " << *it << std::endl;
	}
# endif