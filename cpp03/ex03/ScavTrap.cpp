#include "ScavTrap.hpp"

// OCCF

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "call ScavTrap :: Default Constructor" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "call ScavTrap :: Name Constructor" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap._name)
{
	std::cout << "call ScavTrap :: Copy assignment operator" << std::endl;
	this->_hit_points = scavTrap._hit_points;
	this->_energy_points = scavTrap._energy_points;
	this->_attack_damage = scavTrap._attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	std::cout << "call ScavTrap :: Copy assignment operator" << std::endl;
	if (this != &scavTrap)
	{
		this->_name = scavTrap._name;
		this->_hit_points = scavTrap._hit_points;
		this->_energy_points = scavTrap._energy_points;
		this->_attack_damage = scavTrap._attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "call ScavTrap :: Destructor" << std::endl;
}

// overriding function
void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "Not Enough HP || Not Enough EP" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target \
				<< ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

// add function

void ScavTrap::guardGate()
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "Not a status to guard" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
