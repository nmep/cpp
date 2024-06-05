# include "Serializer.hpp"

Serializer::Serializer( void )
{
	this->_data->value = 0;
	this->_res = 0;
}

Serializer::Serializer( Data *ptr )
{
	this->_data->value = ptr->value;
	this->_res = 0;
}

Serializer::Serializer( Serializer& copy )
{
	*this = copy;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator=( Serializer *rhs )
{
	*this = rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}


int	Serializer::GetDataValue( void ) const
{
	return this->_data->value;
}

std::ostream&	operator<<( std::ostream o, Serializer& rhs )
{
	return o << "value = " << rhs.GetDataValue() << std::endl;
}
