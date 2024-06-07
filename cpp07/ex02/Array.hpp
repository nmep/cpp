# ifndef ARRAY_HPP
	# define ARRAY_HPP

	template < typename T >
	class Array
	{
		private:
				T*	_array;
				unsigned int _size;
		public:
			Array( void ) : _size(0)
			{
				std::cout << "Constructor with empty array" << std::endl;
				this->_array = new T[this->_size];
			}
			Array( unsigned int n ) : _size(n)
			{
				std::cout << "Constructor with unsigned int that create an array size n" << std::endl;
				this->_array = new T[this->_size];
			}

	};

# endif