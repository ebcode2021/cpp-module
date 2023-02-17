#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :
		// OCCF
		FragTrap();
		FragTrap(const FragTrap&);
		FragTrap& operator=(const FragTrap&);
		~FragTrap();
		
		// additional constructor
		FragTrap(std::string);

		// override
		void 	attack(const std::string& target);

		// mothod
		void	highFivesGuys();
};

#endif