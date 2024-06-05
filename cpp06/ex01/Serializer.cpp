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
	// to do
}