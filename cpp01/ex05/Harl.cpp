/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:40:34 by eunson            #+#    #+#             */
/*   Updated: 2023/02/11 15:18:06 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
				<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money."
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
				<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*pointer_func[4])() = { 
		&Harl::debug,
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(levels[i]) == 0)
		{
			(this->*pointer_func[i])();
			return ;
		}
	}
	std::cout << "Error :: Not found Level!" << std::endl;
}