# include "BitcoinExchange.hpp"

bitcoinExchange::bitcoinExchange(void) {}

bitcoinExchange::bitcoinExchange(bitcoinExchange& copy)
{
	std::map<std::string, float>::iterator cit = copy.m.begin();
	std::map<std::string, float>::iterator cite = copy.m.end();

	for (/*nope*/; cit != cite; ++cit)
	{
		this->m[cit->first] = cit->second;
	}
}

bitcoinExchange::~bitcoinExchange() {}

static std::vector<std::string> split(const std::string& str, char delimiter)
{
	std::vector<std::string>	tokens;
	std::string					token;
	size_t		start = 0;
	size_t		end = str.find(delimiter);

	while (end != std::string::npos)
	{
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delimiter, start);
	}
	tokens.push_back(str.substr(start));
	return tokens;
}

static void	parseDate(const std::string & date)
{
	int	Y;
	int	M;

	std::vector<std::string> v;
	if (date.length() == 0)
		throw std::invalid_argument("date can't be empty");
	if (std::count(date.begin(), date.end(), '-') != 2)
		throw std::invalid_argument("date format is Y-M-D");
	for (unsigned int i = 0; i < date.size(); i++)
	{
		if (!isdigit(date[i]) && date[i] != '-')
			throw std::invalid_argument(std::string(1, date[i]) + " invalid argument");
	}
	v = split(date, '-');

	Y = atoi(v[0].c_str());
	M = atoi(v[1].c_str());

	struct tm tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm) || (v[1] == "02"
		&& (v[2] == "30" || v[2] == "31")))
		throw nonValidDate();
	if (v[1] == "02" && v[2] == "29")
	{
		if ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0)
			;
		else
			throw nonValidDate();
	}
}

static void parseValue(const std::string & value)
{
	if (value.length() == 0)
		throw std::invalid_argument("value can't be empty");
	if (std::count(value.begin(), value.end(), '.') > 1)
		throw std::invalid_argument("to many \'.\'");
	for (size_t i = 0; i < value.size(); i++)
	{
		if ((!isdigit(value[i]) && value[i] != '.') && (i != 0 && value[i] == '-'))
		{
			std::cout << "value = " << value << std::endl;
			throw std::invalid_argument("value:" + std::string(1, value[i]) +  " invalid arugment");
		}
	}
}

static void getDateAndValue(std::string line, std::string *date, std::string *value, char delimiter, int print)
{
	*date = line.substr(0, line.find(delimiter));
	if (!date->empty() && (*date)[date->size() - 1] == ' ')
		date->erase(date->size() - 1, date->size());
	try
	{
		parseDate(*date);
	}
	catch(std::invalid_argument& e)
	{
		if (print)
			std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
		throw invalidFile();
	}
	catch(nonValidDate& e)
	{
		if (print)
			std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
		throw invalidFile();
	}
	*value = line.substr(line.find(delimiter) + 1);
	if (!value->empty() && (*value)[0] == ' ')
		value->erase(0, 1);
	try
	{
		parseValue(*value);
	}
	catch (std::invalid_argument& e)
	{
		if (print)
			std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
		throw invalidFile();
	}
}

static float strtof(const std::string & str, int check_oof) // out of range
{
	float res = 0.0f;
	float fractionnalPArt = 1.0f;
	int	i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			throw std::invalid_argument("Error: not a positive number");
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_oof)
		{
			if (res * 10 > 1000 || (res * 10 == 1000 && (str[i] - 48) > '0'))
				throw std::out_of_range("Error: too large a number");
		}
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			fractionnalPArt *= 0.1;
			res+= (str[i] - 48) * fractionnalPArt;
			i++;
		}
	}
	return res;
}

void	bitcoinExchange::parseFile(const std::string& infile)
{
	std::ifstream inputeFile(infile.c_str());
	if (!inputeFile.is_open())
	{
		std::cerr << "Error while open " << infile << std::endl;
		throw invalidFile();
	}
	std::string line;
	getline(inputeFile, line);
	std::string date;
	std::string value;
	while (getline(inputeFile, line))
	{
		try
		{
			getDateAndValue(line, &date, &value, ',', 1);
		}
		catch(invalidFile& e)
		{
			inputeFile.close();
			throw invalidFile();
		}
		try
		{
			this->m[date] = strtof(value, 0);
		}
		catch(const std::out_of_range& e)
		{
			std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
			inputeFile.close();
			throw invalidFile();
		}
		catch(const std::invalid_argument& e)
		{
			std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
			inputeFile.close();
			throw invalidFile();
		}
	}
	inputeFile.close();
}

void	bitcoinExchange::getMap(const std::string& infile)
{
	try
	{
		parseFile(infile);
	}
	catch (std::exception& e)
	{
		throw invalidFile();
	}
}

float	bitcoinExchange::findHashMap(std::string& date)
{
	std::map<std::string, float>::iterator it = this->m.find(date);
	std::map<std::string, float>::iterator ite = this->m.end();

	if (it != ite)
		return it->second;
	else
	{
		it = this->m.lower_bound(date);
		if (it == ite)
		{
			--it;
			return it->second;
		}
		else
		{
			if (it != this->m.begin())
				--it;
			return it->second;
		}
	}
	return it->second;
}

void	bitcoinExchange::getInMap(std::string & infileStr)
{
	float f1;
	float f2;
	std::ifstream inputeFile(infileStr.c_str());
	if (!inputeFile.is_open())
	{
		std::cerr << "Error while open " << infileStr << std::endl;
		throw invalidFile();
	}
	std::string line;
	getline(inputeFile, line);
	std::string date;
	std::string value;
	while (getline(inputeFile, line))
	{
		std::cout << "-------------" << std::endl;
		try
		{
			getDateAndValue(line, &date, &value, '|', 0); // to check
		}
		catch(invalidFile& e)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		try
		{
			f2 = strtof(value, 1);
		}
		catch(const std::out_of_range& e)
		{
			std::cout << e.what() << '\n';
			continue;
		}
		catch(const std::invalid_argument& e)
		{
			std::cout << "Error: too large a number" << std::endl;
			continue;
		}
		f1 = findHashMap(date);
		if (f1 < 0 || f1 > 1000)
		{
			std::cout << "Error: too large a number" << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << f1 * f2 << std::endl;
	}
	inputeFile.close();
}

void	bitcoinExchange::printMap(std::ostream& o)
{
	std::map<std::string, float>::iterator it = this->m.begin();
	std::map<std::string, float>::iterator ite = this->m.end();

	for (/* nope*/; it != ite; ++it)
	{
		o << "date = " << it->first << " | value = " << it->second << std::endl;
	}
}
std::ostream& operator<<(std::ostream& o, bitcoinExchange& other)
{
	other.printMap(o);
	return o;
}