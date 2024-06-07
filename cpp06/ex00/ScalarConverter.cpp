# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	this->nonDisplay = false;
	this->impossible = false;
}

// ScalarConverter::ScalarConverter( const std::string& arg ) 
// {
// 	this->nonDisplay = false;
// 	this->impossible = false;
// }

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

char		ft_stoc( const std::string& str )
{
	std::stringstream ss( str );
	char c;

	ss >> c;
	if (ss.fail())
	{
		throw std::out_of_range("OverFlow");
		return c;
	}
	return c;
}

int	ft_atoi(const std::string& str)
{
	int	i = 0;
	int s = 1;
	int res = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - 48) > INT_MAX % 10))
			|| (res < INT_MIN / 10 || (res == INT_MIN && (str[i] - 48) > INT_MIN % 10)))
		{
			throw std::out_of_range("qwer");
			return 0;
		}
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return res * s;
}

float	ft_stof( const std::string& str )
{
	std::stringstream ss( str );
	float	f;

	ss >> f;
	if (ss.fail())
	{
		throw std::out_of_range("OverFlow");
		return f;
	}
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

int	ft_is_NotANumber( const std::string& str )
{
	if (str == "nan" || str == "nanf" || str == "nanl"
		|| str == "nand32" || str == "nand64" || str == "nand128")
		return 1;
	return 0;
}

int	ft_is_inf( const std::string& str )
{
	if (str == "inf" || str == "-inf" || str == "+inf")
		return 1;
	return 0;
}

int	ScalarConverter::ft_is_C( const std::string& str )
{
	if (str.size() > 1)
		return 0;
	if (!isprint(static_cast<char>(str[0])))
	{
		this->nonDisplay = true;
		return 0;
	}
	if (!isalpha(static_cast<char>(str[0])))
		return 0;
	this->type = CHAR;
	return 1;
}

int	ScalarConverter::ft_is_INT( const std::string& str)
{
	unsigned int i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	for (/*nope*/; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	this->type = INT;
	return 1;
}

int	ScalarConverter::ft_is_double( const std::string& str)
{
	unsigned int	i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	int	count = std::count(str.begin(), str.end(), '.');
	if (count == 0 || count > 1)
		return 0;
	for (/*nope*/; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return 0;
	}
	type = DOUBLE;
	return 1;
}

int ScalarConverter::ft_is_float( const std::string str)
{
	unsigned int	i = 0;

	if (str[str.size() - 1] != 'f')
		return 0;
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
		if (!isdigit(str[i]) && (str[i] != '.' && str[i] != 'f'))
			return 0;
	}
	this->type = FLOAT;
	return 1;
}

int	ScalarConverter::getType( const std::string& str )
{
	int	check_arg = 0;

	if (ft_is_NotANumber( str ))
	{
		this->impossible = 1;
		this->type = NotANumber;
		return 1;
	}
	if (ft_is_inf( str ))
	{
		this->impossible = true;
		this->type = INF;
		return 1;
	}

	check_arg += ft_is_C(str);

	check_arg += ft_is_INT(str);

	check_arg += ft_is_float(str);

	check_arg += ft_is_double(str);
	
	if (check_arg == 0)
		return 0;
	return 1;
}

void ScalarConverter::ft_print_C(const std::string& arg)
{
	 std::cout << "char: ";

	 if (arg.size() == 1 && !isdigit(arg[0]))
	 {
		char c = arg[0];
		if (!isprint(static_cast<unsigned char>(c)))
		{
			std::cout << "Non displayable" << std::endl;
			return;
		}
		std::cout << '\'' << c << '\'' << std::endl;
		return;
	 }
	 std::stringstream ss(arg);
	 int c;
	 ss >> c;
	 if (ss.fail() || !ss.eof())
	 {
		std::cout << "impossible" << std::endl;
		return;
	 }
	 if (c < 0 || c > 127 || !isprint(static_cast<unsigned char>(c)))
	 {
		std::cout << "Non displayable" << std::endl;
		return;
	 }
	 std::cout << '\'' << static_cast<char>(c) << '\'' << std::endl;
}

int		ft_stoi( const std::string& str )
{
	std::stringstream ss( str );
	int	n;

	ss >> n;
	if (ss.fail())
	{
		throw std::out_of_range("OverFlow");
		return n;
	}
	return n;
}

void	ScalarConverter::ft_print_INT( const std::string& arg)
{
	int	n;

	std::cout << "int: ";
	if (ft_is_NotANumber( arg ))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (ft_is_inf( arg ))
	{
		std::cout << "inf" << std::endl;
		return ;
	}
	if (arg.size() == 1)
	{
		int ascii_value = static_cast<int>(arg[0]);
		std::cout << ascii_value << std::endl;
		return ;
	}
	try
	{
		n = ft_stoi(arg);
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
	std::cout << static_cast<int>(n) << std::endl;
}

void	ScalarConverter::ft_print_Float( const std::string& arg)
{
	float	f;
	char *	pEnd;

	std::cout << "float: ";
	if (ft_is_inf(arg))
	{
		std::cout << "inff" << std::endl;
		return ;
	}
	if (ft_is_NotANumber(arg))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (arg.size() == 1)
	{
		float ascii_value = static_cast<float>(arg[0]);
		std::cout  << std::fixed << std::setprecision(2) << ascii_value << 'f' << std::endl;
		return ;
	}
	try
	{
		f = strtof(arg.c_str(), &pEnd);
		// f = static_cast<float>(arg);
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
	std::cout << std::fixed << std::setprecision(2) << static_cast<float>(f) << "f" << std::endl;
}

void	ScalarConverter::ft_print_double( const std::string& arg)
{
	double		f;
	char		*pEnd;
	std::cout << "double: ";
	if (ft_is_inf(arg))
	{
		std::cout << "inf" << std::endl;
		return ;
	}
	if (ft_is_NotANumber(arg))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (arg.size() == 1)
	{
		double ascii_value = static_cast<double>(arg[0]);
		std::cout  << std::fixed << std::setprecision(2) << ascii_value << std::endl;
		return ;
	}
	try
	{
		f = strtod(arg.c_str(), &pEnd);
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
	std::cout <<	std::fixed << std::setprecision(2) << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::convert(const std::string &arg)
{
	ft_print_C(arg);
	ft_print_INT(arg);
	ft_print_Float(arg);
	ft_print_double(arg);
}