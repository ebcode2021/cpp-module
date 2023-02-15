#include "ClapTrap.hpp"

// OCCF

ClapTrap::ClapTrap()
{
	std::cout << "call :: Default Constructor" << std::endl;
	this->_name = "Eunson";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "call :: Name Constructor" << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "call :: Copy Constructor" << std::endl;
	this->_name = clapTrap.getName();
	this->_hit_points = clapTrap.getHitPoints();
	this->_energy_points = clapTrap.getEnergyPoints();
	this->_attack_damage = clapTrap.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	std::cout << "call :: Copy assignment operator" << std::endl;
	this->_name = clapTrap.getName();
	this->_hit_points = clapTrap.getHitPoints();
	this->_energy_points = clapTrap.getEnergyPoints();
	this->_attack_damage = clapTrap.getAttackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "call :: Destructor" << std::endl;
}

// getter

std::string	ClapTrap::getName() const
{
	return (this->_name);
}