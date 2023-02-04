/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:12:40 by eunson            #+#    #+#             */
/*   Updated: 2023/02/03 09:59:50 by eunson           ###   ########.fr       */
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

Weapon::Weapon(const Weapon& origin)
{
	std::cout << "복사 생성자 호출" << std::endl;
	this->_type = origin._type;
}

Weapon& Weapon::operator=(const Weapon& origin) {
	std::cout << "할당 대입 연산자 호출" << std::endl;
	this->_type = origin._type;
	return *this;
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
