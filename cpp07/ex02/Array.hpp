# ifndef ARRAY_HPP
	# define ARRAY_HPP

	# include <iostream>
	# include <exception>
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
				for (unsigned int i = 0; i < this->_size; i++)
				{
					this->_array[i] = 0;
				}
			}
			Array( unsigned int n ) : _size(n)
			{
				std::cout << "Constructor with unsigned int that create an array size n" << std::endl;
				if (n == 0)
				{
					std::cout << "you can't allocate 0 bytes" << std::endl;
					return ;
				}
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
				{
					this->_array[i] = 0;
				}
			}

			template<typename U>
			Array( Array<U>& copy ) : _size(copy.size())
			{
				std::cout << "Constructor by copy" << std::endl;
				this->_array = new T[copy.size()];
				for (unsigned int i = 0; i < this->_size; i++)
				{
					this->_array[i] = static_cast<T>(copy[i] + 1);
				}
			}
			~Array()
			{
				delete[] this->_array;
			}

			void	display()
			{
				if (this->_size == 0 || !this->_array[0])
				{
					std::cout << "empty array can't be displayed" << std::endl;
					return ;
				}
				for (unsigned int i = 0; i < this->_size; i++)
				{
					if (this->_array[i] != 0)
						std::cout << "array[" << (i) << "] = " << this->_array[i] << std::endl;
				}
			}
			
			unsigned int size() const {
				return this->_size;
			}

			void SetArray(int val)
			{
				for (unsigned int i = 0; i < this->_size; i++)
				{
					this->_array[i] = val;
				}
			}

			T&	operator[]( unsigned int index) const
			{
				if (index > this->_size)
					throw std::exception();
				return this->_array[index];
			}

			template<typename R>
			Array<T>& operator=( Array<R>& rhs )
			{
				delete [] this->_array;
				this->_size = rhs.size();
				this->_array = new T[rhs.size()];
				for (unsigned int i = 0; i < rhs.size(); i++)
				{
					this->_array[i] = static_cast<T>(rhs[i] + 1);
				}
				return *this;
			}

	};

# endif