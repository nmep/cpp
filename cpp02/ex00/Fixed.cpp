# include "Fixed.hpp"

const int Fixed::_fractionBits = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed &copy )
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_value = copy.getRawBits();
}

Fixed &	Fixed::operator=( Fixed const & other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->_value = other._value;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member functions called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

