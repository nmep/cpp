# ifndef ITER_HPP
	# define ITER_HPP
	
	# include <iostream>

	template< typename D>
	void	ft_putstr(D const & array_var)
	{
		std::cout << array_var;
	}

	template< typename T, typename L, typename F>
	void iter( T* a, L b, F c )
	{
		for (unsigned int i = 0; i < b; i++)
		{
			c(a[i]);
		}
		std::cout << std::endl;
	}

# endif