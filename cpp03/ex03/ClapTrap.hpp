# ifndef	__CLAPTRAP__
	# define	__CLAPTRAP__

	# include <iostream>

	class ClapTrap
	{
		protected:
			std::string _name;
			unsigned int	_HitPoint;
			unsigned int	_EnergyPoint;
			unsigned int _AttackDamage;

		public:
			ClapTrap( void );
			ClapTrap( const std::string name );
			ClapTrap( const ClapTrap &copy );
			~ClapTrap();

			const std::string					GetName( void );
			unsigned int						GetHitPoint( void );
			unsigned int						GetEnergyPoint( void );
			unsigned int						GetAttackDamage( void );

			void	attack(const std::string & target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);

			ClapTrap&	operator=(const ClapTrap& rhs);
	};

# endif