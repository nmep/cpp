# include "Fixed.hpp"

// static int const _int_fractionBits = 8;
// static int const _float_fractionBits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default contructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & other )
{
	std::cout << "Copy assignment called" << std::endl;
	this->_value = other._value;
	return *this;
}

Fixed::Fixed( Fixed const &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = copy.getRawBits();
}

Fixed::Fixed( int const integer )
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = integer * static_cast<int>(this->_fractionBits * this->_fractionBits);
}

Fixed::Fixed( float const f )
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (pow(2, this->_fractionBits)));
}

int	Fixed::getRawBits( void ) const
{
	return this->_value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "Set RawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	int	Integer_part;
	int	Fractional_part;

	Integer_part = this->_value >> this->_fractionBits;
	Fractional_part = this->_value & (this->_value << (this->_fractionBits - 1));

	return Integer_part + (Fractional_part / pow(2, this->_fractionBits));
}

int	Fixed::toInt( void ) const
{
	int	Integer_part;
	int	Fractional_part;

	Integer_part = this->_value >> this->_fractionBits;
	Fractional_part = this->_value & (this->_value << (this->_fractionBits - 1));

	return Integer_part + (Fractional_part / static_cast<int>(pow(2, this->_fractionBits)));
}

std::ostream & operator<<(std::ostream & o, Fixed const & other)
{
	o << other.getRawBits();
	return o;
}