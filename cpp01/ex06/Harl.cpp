# include "Harl.hpp"

void	Harl::_debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

Harl::Harl( void )
{
	// _mem_ptr{&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error}
	_mem_ptr[0] = &Harl::_debug;
	_mem_ptr[1] = &Harl::_info;
	_mem_ptr[2] = &Harl::_warning;
	_mem_ptr[3] = &Harl::_error;
	std::cout << "Harl Constructor" << std::endl;
}

Harl::~Harl( void )
{
	std::cout << "Harl Destructor" << std::endl;
}

void	Harl::complain( std::string level )
{
	int index = std::atoi(level.c_str());
	if (index >= 1 && index <= 4)
	{
		while (index < 5)
		{
			switch (index)
			{
				case 1:
					(this->*_mem_ptr[0])();
					break ;
				case 2:
					(this->*_mem_ptr[1])();
					break ;
				case 3:
					(this->*_mem_ptr[2])();
					break ;
				case 4:
					(this->*_mem_ptr[3])();
					break ;
			}
			index++;
		}
	}
	else
		std::cout << "Not a valide level" << std::endl;
}