#include "ClapTrap.hpp"

// OCCF

ClapTrap::ClapTrap()
{
	std::cout << "call :: Default Constructor" << std::endl;
	this->_name = "default";
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

unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_attack_damage);
}

// method

void ClapTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "Not Enough HP || Not Enough EP" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target \
				<< ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "Already dead.." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " take " << amount \
				<< " points of damage!" << std::endl;
	if (this->_hit_points < amount)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "Already dead.." << std::endl;
		return ;
	}
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "Nope!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " take " << amount \
				<< " points of repaired!" << std::endl;
	this->_energy_points -= 1;
	this->_hit_points += amount;
}

void	ClapTrap::printStatus() const
{
	std::cout << "[ " << this->_name<< " ]" << std::endl;
	std::cout << " - Hit points : " << this->_hit_points << std::endl;
	std::cout << " - Energy points : " << this->_energy_points << std::endl;
	std::cout << " - Attack damage : " << this->_attack_damage << std::endl;
}