# ifndef	__SCAVTRAP__
	# define	__SCAVTRAP__

	# include <iostream>
	# include "ClapTrap.hpp"

	class ScavTrap :  virtual public ClapTrap
	{
		public:
			ScavTrap( void );
			ScavTrap( const std::string name);
			~ScavTrap();

			std::string			GetName( void );
			void				attack(const std::string &target);
			void				guardGate( void );

	};

# endif