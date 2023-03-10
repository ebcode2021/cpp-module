/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:19:50 by eunbison          #+#    #+#             */
/*   Updated: 2023/02/11 15:22:01 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "[DEBUG]" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\n---------------" << std::endl;
	
	std::cout << "[INFO]" << std::endl;
	harl.complain("INFO");
	std::cout << "\n---------------" << std::endl;

	std::cout << "[WARNING]" << std::endl;
	harl.complain("WARNING");
	std::cout << "\n---------------" << std::endl;

	std::cout << "[ERROR]" << std::endl;
	harl.complain("ERROR");
	std::cout << "\n---------------" << std::endl;

	std::cout << "[Not found Level]" << std::endl;
	harl.complain("lalala");
}
