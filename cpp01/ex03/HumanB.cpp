/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:14:09 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 15:31:31 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() :  _weapon(NULL), _name("none") {}

HumanB::HumanB(std::string name) :  _weapon(NULL), _name(name) {}

HumanB::~HumanB(){}

void HumanB::attack(void)
{
	if (this->_weapon == NULL)
		std::cout << this->_name << "은(는) 무기가 없어서 맨손으로 때렸습니다. 얍얍." << std::endl;
	else
	{
		std::cout << this->_name << " attacks with their "
					<< this->_weapon->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon =  &weapon;
}

