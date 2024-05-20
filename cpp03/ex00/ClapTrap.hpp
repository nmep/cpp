# ifndef	__CLAPTRAP__
	# define	__CLAPTRAP__

	# include <iostream>

	class ClapTrap
	{
		private:
			const std::string _name;
			int	_HitPoint;
			int	_EnergyPoint;
			int _AttackDamage;

		public:
			ClapTrap(void);
			ClapTrap( const std::string name);
			~ClapTrap();

			const std::string					GetName( void );
			int						GetHitPoint( void );
			int						GetEnergyPoint( void );
			int						GetAttackDamage( void );

			void	attack(const std::string & target);
			void	takeDamage(int amount);
			void	beRepaired(int amount);
	};

# endif