# ifndef	__DIAMONDTRAP__
	# define	__DIAMONDTRAP__

	# include "ScavTrap.hpp"
	# include "FragTrap.hpp"

	class DiamondTrap : public ScavTrap, public FragTrap
	{
		private:
			const	std::string	_name;
			int					_hitPoint;
			int					_EnergyPoint;
			int					_attackDamage;

		public:
			DiamondTrap( void );
			DiamondTrap( const std::string name);
			~DiamondTrap();

			const std::string GetName( void );
			void	attack(const std::string& target);
			void	WhoAmI( void );

	};

# endif