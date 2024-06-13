# ifndef MUTANTSTACK_HPP
	# define MUTANTSTACK_HPP
	# include <iostream>
	# include <stack>
	# include <iterator>

	template <typename T, typename Container = std::deque<T> >

	class MutantStack : public std::stack<T>
	{
		public:
			MutantStack() : std::stack<T, Container> () {};
			~MutantStack() {};
			MutantStack( const MutantStack & copy ) {
				*this = copy;
			}
			MutantStack&	operator=(MutantStack const & rhs) {
				this->c = rhs->c;
				return *this;
			}
			typedef typename MutantStack::container_type::iterator iterator;
			iterator begin() {
				return this->c.begin();
			}
			iterator end() {
				return this->c.end();
			}
	};

# endif