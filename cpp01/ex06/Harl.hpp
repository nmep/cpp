#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstdlib>

class Harl
{
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
		void	(Harl::*_mem_ptr[4])( void );

	public:
		Harl( void );
		~Harl();
		void	complain( std::string level );
};

# endif