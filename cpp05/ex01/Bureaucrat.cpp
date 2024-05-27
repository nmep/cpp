# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat( const std::string & name ) : _name(name), _grade(150) {}  

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat( const std::string& name, const std::string& grade ) : _name(name)
{
	this->setGrade( grade );
}

const std::string	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const { return this->_grade; }

void	Bureaucrat::setGrade( const std::string& grade )
{
	try
	{
		this->_grade = this->ft_atoi(grade);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	Bureaucrat::ft_atoi( const std::string& str )
{
	int	i = 0;
	int	s = 1;
	int	res = 0;

	if (str.length() > 3 || str[0] == '-')
	{
		throw std::out_of_range(" 1 <= grade <= 150");
		return 0;
	}
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			throw Bureaucrat::GradeTooLowException();
			return 0;
			s *= -1;
		}
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
	{
		throw std::invalid_argument ("Invalid argument in the string");
		return 0;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (res > 150 / 10 || (res == 150 / 10 && (str[i] - 48) > 150 % 10))
		{
			throw Bureaucrat::GradeTooHighException();
			return 0;
		}
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res == 0)
	{
		throw Bureaucrat::GradeTooLowException();
		return 0;
	}
	return res;
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("The Grade of the bureaucrat is to high to be instantiate");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("The Grade of the bureaucrat is to low to be instantiate");
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat& other)
{
	this->_grade = other.getGrade();
	return *this;
}


std::ostream& operator<<( std::ostream& out, Bureaucrat& frog )
{
	return out << frog.getName() << ", bureaucrat grade " << frog.getGrade() << std::endl;
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade <= 1)
		return throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade >= 150)
		return throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}