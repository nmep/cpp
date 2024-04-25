# include <iostream>

using namespace std;

void	str_to_upper(const char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			cout << (char) toupper(str[i]);
		else
			cout << str[i];
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl, 0);
	while (*(++av) && *(av + 1))
	{
		str_to_upper(*av);
		cout << " ";
	}
	str_to_upper(*av);
	cout << endl;
}