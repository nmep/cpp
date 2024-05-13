# ifndef	__DIAMONDTRAP__
	# define	__DIAMONDTRAP__

	# include "ScavTrap.hpp"
	# include "FragTrap.hpp"

	class DiamondTrap : public ScavTrap, public FragTrap
	{
		private:
			const std::string _name;
		public:
			DiamondTrap( void );
			DiamondTrap( const std::string name);
			~DiamondTrap();
	};

# endif