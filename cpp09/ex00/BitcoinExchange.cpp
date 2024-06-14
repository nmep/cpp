# include "BitcoinExchange.hpp"

bitcoinExchange::bitcoinExchange(void) {}

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
		if (!isdigit(value[i]) && value[i] != '.')
			throw std::invalid_argument("value:" + std::string(1, value[i]) +  " invalid arugment");
	}

}

static void getDateAndValue(std::string line, std::string *date, std::string *value)
{
	*date = line.substr(0, line.find(','));
	try
	{
		parseDate(*date);
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
		throw invalidFile();
	}
	catch(nonValidDate& e)
	{
		std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
		throw invalidFile();
	}

	*value = line.substr(line.find(',') + 1);
	try
	{
		parseValue(*value);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << RED << e.what() << '\n' << "\tline: " << '\'' << line << '\'' << RESET << std::endl;
		throw invalidFile();
	}
}

static float strtof(const std::string & str)
{
	int i = 0;
	int s = 1;
	float res = 0.0;
	float fractFactor = 1.0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10.0) + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			fractFactor *= 0.1;
			res += (str[i] - 48) * fractFactor;
			i++;
		}
	}
	std::cout << "atof i = " << i << std::endl;
	return  res * s;
}

void	bitcoinExchange::parseFile(std::string& infile)
{
	// get file
	std::ifstream inputeFile(infile.c_str());
	if (!inputeFile.is_open())
	{
		std::cerr << "Error while open " << infile << std::endl;
		throw invalidFile();
	}
	// get line
	std::string line;
	getline(inputeFile, line);
	std::string date;
	std::string value;
	while (getline(inputeFile, line))
	{
		// check line
		try
		{
			getDateAndValue(line, &date, &value); // to check
		}
		catch(invalidFile& e)
		{
			throw invalidFile();
		}
		// if line is good convert value in int
		float f = strtof(value);
		std::cout << "value = " << value << std::endl;
		std::cout << "f apres convertion = " << f << std::endl;
		// insert it to map;
		// this->m[date] = strtof(value);
	}
}

void	bitcoinExchange::getMap(std::string& infile)
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
