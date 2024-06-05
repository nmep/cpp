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

int	ScalarConverter::ft_is_C( const std::string& str )
{
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (!isprint(str[i]))
		{
			this->nonDisplay = true;
			return 0;
		}
		if (!isalpha(str[i]))
			return 0;
	}
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

void	ft_print_C( std::stringstream& arg )
{
	int	c;

	arg >> c;

	std::cout << "char: " << static_cast<char>(c) << std::endl;
}

void	ScalarConverter::convert(const std::string &arg)
{
	std::stringstream ss(arg);
	switch (this->type)
	{
		case CHAR:
			ft_print_C(ss);
	}
}