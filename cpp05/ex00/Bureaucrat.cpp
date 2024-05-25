# include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat( const std::string & name ) : _name(name), _grade(150) {}  

Bureaucrat::~Bureaucrat() {}

const std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const { return this->_grade; }

void	Bureaucrat::setGrade( const std::string& grade )
{
	this->_grade = std::atoi(grade.c_str());
}

int	atoi( const std::string& str )
{
	int	i = 0;
	int	s = 1;
	int	res = 0;

	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
	{
		throw std::invalid_argument ("Invalid argument in the string\n");
		return ;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (res > INT32_MAX / 10 || (res == INT32_MAX / 10 && (str[i] - 48) > INT32_MAX % 10))
		{
			throw std::out_of_range("Overflow of str in atoi\n");
			return ;
		}
		res = res * 10 + (str[i] - 48);
		i++;
	}
}
