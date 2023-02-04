/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:13:24 by eunson            #+#    #+#             */
/*   Updated: 2023/02/02 22:23:06 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :  _weapon(weapon), _name(name) {}

HumanA::~HumanA(){}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their "
				<< this->_weapon.getType() << std::endl;
}
