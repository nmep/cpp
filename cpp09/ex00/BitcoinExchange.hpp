# ifndef BITCOINEXCHANGE_HPP
	# define BITCOINEXCHANGE_HPP
	# include <iostream>
	# include <fstream>
	# include <map>
	# include <bits/stdc++.h>
	# include <sstream>
	# include <vector>
	# include <ctime>

	# define RED "\033[31m"
	# define RESET "\033[0m"
	class bitcoinExchange
	{
		private:
			std::map<std::string, float>	m;

		public:
			bitcoinExchange(void);
			// bitcoinExchange(bitcoinExchange & copy);
			~bitcoinExchange();
			void	parseFile(std::string& infile);
			void	getMap(std::string& infile);
	};

// exception

	class invalidFile : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return "Invalid file";
			}
	};

	class nonValidDate : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return "Date don't exist";
			}
	};


// surcharge d'operateur << qui affichage la map entiere

// // get line
	// while (getline(inputeFile, line)) {
	// 	std::cout << line << std::endl;
	// 	date = line.substr(0, line.find(","));
	// 	value = line.substr(line.find(",") + 1);
	// 	// std::cout << "date = " << date << " value = " << value << std::endl;
		
	// }

// std::string line;
// std::string date;
// std::string value;

// // map sera un objet

// std::map<std::string, T>


// inputeFile.close();

# endif