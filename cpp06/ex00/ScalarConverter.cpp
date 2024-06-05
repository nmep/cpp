# include "ScalarConverter.hpp"
# include "Exception.hpp"

ScalarConverter::ScalarConverter( void )
{
	this->nonDisplay = false;
	this->impossible = false;
}

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
// char		ft_stoc( const std::string& str )
// {
// 	std::stringstream ss( str );
// 	char c;

// 	ss >> c;
// 	if (ss.fail())
// 	{
// 		throw std::out_of_range("OverFlow");
// 		return c;
// 	}
// 	return c;
// }

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
	int res;
	try
	{
		res = ft_stoi(str);
	}
	catch(std::exception& e)
	{
		return 0;
	}
	if (!isprint(static_cast<char>(res)))
	{
		this->nonDisplay = true;
		return 0;
	}
	if (!isalpha(static_cast<char>(res)))
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

void	ScalarConverter::ft_print_C( const std::string& arg )
{
	int	c;

	std::cout << "char: ";
	if (this->nonDisplay)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	if (this->impossible)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	try
	{
		c = ft_stoi(arg);
	}
	catch ( std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
	std::cout << static_cast<char>(c) << std::endl;
}

void	ScalarConverter::ft_print_INT( const std::string& arg)
{
	int	n;

	std::cout << "int: ";
	if (this->impossible)
	{
		std::cout << arg << std::endl;
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

	std::cout << "float: ";
	if (this->impossible)
	{
		std::cout << arg << std::endl;
		return ;
	}
	try
	{
		f = ft_stof(arg);
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

	std::cout << "double: ";
	if (this->impossible)
	{
		std::cout << arg << std::endl;
		return ;
	}
	try
	{
		f = ft_stod(arg);
	}
	catch (std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
	std::cout <<  std::fixed << std::setprecision(2) << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::convert(const std::string &arg)
{
	void	(ScalarConverter::*print_tab_ptr[4])( const std::string& arg) = {
		&ScalarConverter::ft_print_C,
		&ScalarConverter::ft_print_INT,
		&ScalarConverter::ft_print_double,
		&ScalarConverter::ft_print_Float,
		};
	// std::stringstream ss(arg);
	switch (this->type)
	{
		case CHAR:
			ft_print_C(arg);
			break;
		case INT:
			ft_print_INT(arg);
			break ;
		case FLOAT:
			ft_print_Float(arg);
			break;
		case DOUBLE:
			ft_print_double(arg);
			break;
		default:
			break;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i + 1 == this->type)
			continue;
		(this->*print_tab_ptr[i])(arg);
	}
}