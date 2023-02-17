#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name")
{
	std::cout << "call DiamondTrap :: Default Constructor" << std::endl;
	this->_name = "Diamond";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "call DiamondTrap :: Name Constructor" << std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap._name + "_clap_name")
{
	std::cout << "call DiamondTrap :: Copy assignment operator" << std::endl;
	this->_name = diamondTrap._name;
	this->_hit_points = diamondTrap._hit_points;
	this->_energy_points = diamondTrap._energy_points;
	this->_attack_damage = diamondTrap._attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << "call DiamondTrap :: Copy assignment operator" << std::endl;
	if (this != &diamondTrap)
	{
		this->_name = diamondTrap._name;
		this->_hit_points = diamondTrap._hit_points;
		this->_energy_points = diamondTrap._energy_points;
		this->_attack_damage = diamondTrap._attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "call DiamondTrap :: Destructor" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name :" << this->_name << "\n" 
				<< "ClapTrap name : " << ClapTrap::_name << std::endl;
}
