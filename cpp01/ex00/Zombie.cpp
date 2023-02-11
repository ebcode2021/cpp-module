/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:13:45 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 15:34:53 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "eunson";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "죽는 애 -> " << this->_name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
