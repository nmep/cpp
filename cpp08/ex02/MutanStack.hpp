# ifndef MUTANTSTACK_HPP
	# define MUTANTSTACK_HPP
	# include <iostream>
	# include <stack>
	# include <iterator>

	template <typename T, typename Container = std::deque<T> >

	class MutantStack : public std::stack<T>
	{
		public:
			typedef T*	it;

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
			void push_multiple(const T* array, int count)
			{
				for (int i = 0; i < count; i++)
				{
					this->push(array[i]);
				}
			}
	};

template <typename T, typename Container>
std::ostream& operator<<(std::ostream & o, MutantStack<T, Container> & other)
{
	typename MutantStack<T, Container>::iterator it;

	if (other.begin() == other.end())
	{
		o << "this stack is empty" << std::endl;
		return o;
	}
	for (it = other.begin(); it != other.end(); ++it)
	{
		o << *it << std::endl;
	}
	return o;
}

# endif