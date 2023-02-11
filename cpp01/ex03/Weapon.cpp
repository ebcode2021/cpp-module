/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:12:40 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 15:14:45 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	this->_type = "nothing";
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void){}

std::string& Weapon::getType(void)
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
