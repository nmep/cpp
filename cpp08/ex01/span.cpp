# include "Span.hpp"

Span::Span( void ) : _size(0)
{
	std::cout << "default constructor size = " << this->_size << std::endl;
	this->it = this->_v.begin();
}

Span::Span( unsigned int n ) : _size(n)
{
	std::cout << "non signed constructor called size = " << this->_size << std::endl;
	this->it = this->_v.begin();
}

Span::~Span() {}

unsigned int	Span::getSize( void ) const
{
	return this->_size;
}

void	Span::addNumber( int value )
{
	if (this->_v.size() >= this->_size)
	{
		std::cout << "this vector can't contain anymore value" << std::endl;
		throw std::exception();
		return ;
	}
	this->_v.push_back(value);
	std::cout << value << " has been pushed successfuly in the vector" << std::endl;
}

int	Span::shortestSpan( void )
{
	if (this->_size <= 1)
		throw std::logic_error("not enough value in this vector to find a span");

	std::vector<int> sorted(_v);

	std::sort(sorted.begin(), sorted.end());
	int	minSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < minSpan)
			minSpan = sorted[i] - sorted[i - 1];
	}
	return minSpan;
}

int	Span::longestSpan( void )
{
	if (this->_size <= 1)
		throw std::logic_error("not enough value in this vector to find a span");

	std::vector<int> sorted(_v);

	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it_b = sorted.begin();
	std::vector<int>::iterator it_e = sorted.end();
	it_e--;

	return *(it_e) - *it_b;
}