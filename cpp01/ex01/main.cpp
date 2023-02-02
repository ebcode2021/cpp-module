/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:58:32 by eunson            #+#    #+#             */
/*   Updated: 2023/02/02 20:41:43 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

int main(void)
{
	int	total_zombie;

	total_zombie = 5;
	Zombie *horde = zombieHorde(total_zombie, "random zombie");
	for (int i = 0; i < total_zombie; i++)
		horde[i].announce();
	delete[] horde;
}
