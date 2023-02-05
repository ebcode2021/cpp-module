/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:19:50 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/05 20:29:50 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	Harl harl;
	harl.complain(argv[1]);
}
