# include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << YELLOW << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain( Brain &copy )
{
	std::cout << YELLOW << "Brian copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain::~Brain()
{
	std::cout << YELLOW << "Brain destructor called" << RESET << std::endl;
}

Brain&	Brain::operator=( Brain& rhs )
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

std::string	Brain::getIdeas( int i ) const
{
	if (i < 0)
		std::cerr << "the idea you want must be >= 0" << std::endl;

	if (this->ideas[i].empty())
		std::cerr << "idead[" << i << "] is empty" << std::endl;

	return this->ideas[i];
}

void	Brain::setIdea( const std::string idea )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

void	Brain::ShowIdea( void ) const
{
	for (int i = 0; i < 100; i++)
		std::cout  << this->ideas[i] << std::endl;
}
