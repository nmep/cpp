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
// qwerqwerweq
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
		|| str == "nand32" || str == "nand64" || str == "nand128"
		|| str == "inf" || str == "-inf" || str == "+inf")
		return 1;
	return 0;
}

int	ft_is_inf( const std::string& str )
{
	if (str == "inf" || str == "-inf" || str == "+inf")
		return 1;
	return 0;
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

int	ft_isC( const std::string& str , int *type)
{
	if (ft_is_nan( str ))
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
		if (!isalpha(str[i]))
			return 0;
	}
	*type = CHAR;
	return 1;
}

int	ft_get_C( const std::string& str , int *type, bool *impossible, bool *nonDisplay)
{
	try
	{
		ft_isC( str , type);
	}
	catch(const NonDisplayable& e)
	{
		std::cerr << e.what() << '\n';
		*nonDisplay = true;
	}
	catch( const ImpossibleException& e)
	{
		std::cerr << e.what() << '\n';
		*impossible = true;
		return 1;
	}
	*type = CHAR;
	return 1;
}

int	ft_is_INT( const std::string& str, int *type, bool *impossible)
{
	unsigned int i = 0;

	if (ft_is_nan(str) || ft_is_inf(str))
	{
		*impossible = true;
		return 1;
	}
	if (str[0] == '-' || str[0] == '+')
		i++;
	for (/*nope*/; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	*type = INT;
	return 1;
}

int	ft_is_double( const std::string& str, int *type, bool *impossible)
{
	unsigned int	i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	if (ft_is_nan(str) || ft_is_inf(str))
	{
		*impossible = true;
		return 1;
	}
	int	count = std::count(str.begin(), str.end(), '.');
	if (count == 0 || count > 1)
		return 0;
	for (/*nope*/; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return 0;
	}
	*type = DOUBLE;
	return 1;
}

int ft_is_float( const std::string str, int *type, bool *impossible)
{
	unsigned int	i = 0;

	// const char bakcstr = str.back();
	if (ft_is_nan(str) || ft_is_inf(str))
	{
		*impossible = true;
		return 1;
	}
	if (str[str.size() - 1] != 'f')
		return 0;
	std::cout << "dernier charactere = " << str[str.size() - 1] << std::endl;
	if (str[0] == '-' || str[0] == '+')
		i++;
	int	count = std::count(str.begin(), str.end(), '.');
	if (count == 0 || count > 1)
		return 0;
	count = std::count(str.begin(), str.end(), 'f');
	if (count == 0 || count > 1)
		return 0;
	for (/* nope */; i < str.size(); i++)
	{
		if (!isdigit(str[i] && (str[i] != '.' || str[i] != 'f')))
			return 0;
	}
	*type = FLOAT;
	return 1;
}

int	getType( const std::string& str , int *type, bool *impossible, bool *nonDisplay)
{
	int	check_arg = 0;

	check_arg += ft_get_C(str, type, impossible, nonDisplay);
	
	check_arg += ft_is_INT(str, type, impossible);

	check_arg += ft_is_double(str, type, impossible);
	
	check_arg += ft_is_float(str, type, impossible);

	if (check_arg == 0 && impossible)
		return 0;
	return 1;
}
