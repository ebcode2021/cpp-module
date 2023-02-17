#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		// OCCF
		ScavTrap();
		ScavTrap(const ScavTrap&);
		ScavTrap& operator=(const ScavTrap&);
		~ScavTrap();

		// additional constructor
		ScavTrap(std::string);

		// override
		void	attack(const std::string& target);

		// method
		void	guardGate();
};

#endif