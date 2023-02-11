/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:09:39 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 15:45:26 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main(void)
{
	Zombie zombie1("eunbi");
	Zombie zombie2;
	Zombie* pointer_zombie;

	randomChump("pikachu");
	{
		Zombie a("A");
		Zombie b("B");
		Zombie *p_zombie = newZombie("eunson1");
		p_zombie->announce();
		delete p_zombie;
	}
	pointer_zombie = newZombie("pointer zombie");
	pointer_zombie->announce();
	zombie1.announce();
	zombie2.announce();
	delete pointer_zombie;
}
