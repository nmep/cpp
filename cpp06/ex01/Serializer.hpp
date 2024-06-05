# ifndef SERIALIZER_HPP
	# define SERIALIZER_HPP

	# include <iostream>
	# include <stdint.h>
	# include "Data.hpp"

	class Serializer
	{
		private:
			Data* _data;
			uintptr_t _res;
		public:
			Serializer( void );
			Serializer( Data* ptr );
			Serializer( Serializer& copy );
			~Serializer();

			Serializer&	operator=( Serializer *rhs );

			int	GetDataValue( void ) const;
			uintptr_t serialize(Data* ptr);
			Data* deserialize(uintptr_t raw);
	};

std::ostream&	operator<<( std::ostream o, Serializer& rhs );

# endif