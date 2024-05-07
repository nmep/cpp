# include <iostream>



class student
{
	private:
		std::string _login;
	
	public:
		student (std::string login) : _login(login)
		{
			;
		}

		std::string	get_login()
		{
			return this->_login;
		}

		std::string* get_login_ptr()
		{
			return &(this->_login);
		}

		std::string&	get_login_ref()
		{
			return this->_login;
		}
};


int	main()
{
	student	stud("lgarfi");
	std::cout << stud.get_login() << std::endl;
	std::cout << *(stud.get_login_ptr()) << std::endl;
	std::cout << stud.get_login_ref() << std::endl;
}