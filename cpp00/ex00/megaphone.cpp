# include <iostream>


void	str_to_upper(const char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			std::cout << (char) toupper(str[i]);
		else
			std::cout << str[i];
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (*(++av) && *(av + 1))
	{
		str_to_upper(*av);
		std::cout << " ";
	}
	str_to_upper(*av);
	std::cout << std::endl;
}
