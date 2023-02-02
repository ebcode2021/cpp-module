/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:09:39 by eunson            #+#    #+#             */
/*   Updated: 2023/02/02 19:40:28 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name);
Zombie* newZombie( std::string name );

int main(void)
{
	Zombie zombie1("eunbi");
	Zombie zombie2;
	Zombie* pointer_zombie;

	randomChump("pikachu");

	pointer_zombie = newZombie("pointer zombie");
	pointer_zombie->announce();
	zombie1.announce();
	delete pointer_zombie;
	zombie2.announce();
}
