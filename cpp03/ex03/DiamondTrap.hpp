#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string	_name;

	public :
		// OCCF
		DiamondTrap();
		DiamondTrap(const DiamondTrap&);
		DiamondTrap& operator=(const DiamondTrap&);
		~DiamondTrap();

		// additional constructor
		DiamondTrap(std::string);

		// override
		void 	attack(const std::string& target);

		// method
		void	whoAmI();

};

#endif