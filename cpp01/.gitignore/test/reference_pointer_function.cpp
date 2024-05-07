# include <iostream>

using namespace std;

void	ft_print_str(string str)
{
	cout << str << endl;
}

void	ft_print_ptr(string *str)
{
	cout << *str + " pointeur" << endl;
}

void	ft_print_ref(string const & str)
{
	cout << str + " ref" << endl;
}

int	main()
{
	string	str = "bonjour";
	string 	*str_ptr = &str;


	string &	str_ref = str;

	str_ref = "aurevoir";
	ft_print_str(str);
	ft_print_ptr(str_ptr);
	ft_print_ref(str_ref);

}