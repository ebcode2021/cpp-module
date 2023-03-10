/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:19:50 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/05 19:19:38 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Join.hpp"

static void	print_error_with_exit(std::string msg)
{
	std::cout << "Error :: " << msg << std::endl;
	exit (EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		print_error_with_exit("Check arguements count");
	Join::replace(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
}
