# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

// ScalarConverter::ScalarConverter( const ScalarConverter& copy )
// {
// 	*this = copy;
// }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=( ScalarConverter& rhs )
{
	(void)rhs;
	return *this;
}

int		ft_stoi( const std::string& str )
{
	std::stringstream ss( str );
	int	n;

	ss >> n;
	if (ss.fail())
	{
		std::cout << "Stoi: error or invalid arg or overflow" << std::endl;
	}
	return n;
}

int	ft_is_nan( const std::string& str )
{
	if (str == "nan" || str == "nanf" || str == "nanl"
		|| str == "nand32" || str == "nand64" || str == "nand128")
		return 0;
	return 1;
}

float	ft_stof( const std::string& str )
{
	std::stringstream ss( str );
	float	f;

	ss >> f;
	if (ss.fail())
		throw std::out_of_range("OverFlow");
	return f;
}

double	ft_stod( const std::string& str )
{
	std::stringstream ss( str );
	double	d;

	ss >> d;
	if (ss.fail())
		throw std::out_of_range("OverFlow");
	return d;
}

int	ft_isC( const std::string& str )
{
	if (!ft_is_nan( str ))
	{
		throw ImpossibleException();
		return 0;
	}
	for (int i = 0; i < static_cast<int>(str.length()) && isalpha(str[i]); i++)
	{
		if (!isprint(str[i]))
		{
			throw NonDisplayable();
			return 0;
		}
	}
	return 1;
}

void	getType( const std::string& str )
{
	try
	{
		ft_isC( str );
	}
	catch(const NonDisplayable& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch( const ImpossibleException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

const char* ImpossibleException::what( void ) const throw()
{
	return "Impossible";
}
 
const char*	NonDisplayable::what( void ) const throw()
{
	return "Non Displayable";
}

const char *	NoType::what() const throw()
{
	return "Not a type";
}
