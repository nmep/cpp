# ifndef	__FRAGTRAP__
	# define	__FRAGTRAP__
		# include "ClapTrap.hpp"

	class FragTrap : virtual public ClapTrap
	{
		public:
			FragTrap( void );
			FragTrap( const std::string name);
			~FragTrap();
			void	attack(const std::string &target);
			void	highFivesGuys( void );
	};

# endif