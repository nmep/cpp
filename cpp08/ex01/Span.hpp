# ifndef SPAN_HPP
	# define SPAN_HPP

	# include <algorithm>
	# include <iostream>
	# include <iterator>
	# include <vector>

	class Span
	{
		private:
			std::vector<int> _v;
			std::vector<int>::iterator it;
			unsigned int _size;
		public:
			Span();
			Span(unsigned int n);
			Span(Span const & copy);
			~Span();

			unsigned int	getSize(void) const;
			void			addNumber(int value);
			int				shortestSpan( void );
			int				longestSpan( void );

			Span&	operator=(Span const & rhs);
			void	printV();
	};

std::ostream & operator<<(std::ostream & o, Span & other);

# endif