/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:17:43 by eunson            #+#    #+#             */
/*   Updated: 2023/01/27 17:56:38 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

#include "PhoneBook.hpp"
//#include "utils.cpp"

void	deadSignalCheck(void);
#define WIDTH 10;

void	PhoneBook::add(int idx)
{
	this->contact[idx].add();
}

void	printHeader(void)
{
	const char*	header[4] = {"index", "first name", "last name", "nickname"};
	
	for (int i = 0; i < 4; i++)
	{
		std::cout.width(10);
		std::cout << header[i];
		if (i < 3)
			std::cout << "|";
		else
			std::cout << std::endl;
	}
}

void	PhoneBook::searchInformation(void)
{
	int			idx;
	std::string input;

	std::cout << "Please enter the index of the contact you want to see : ";
	std::getline(std::cin, input);
	idx = std::atoi(input.c_str());
	if (idx >= 1 && idx <= 8)
		this->contact[idx - 1].showDetail();
}

void	PhoneBook::search(void)
{
	printHeader();
	for (int i = 0; i < 8; i++)
	{
		std::cout.width(10);
		std::cout << i + 1;
		std::cout << "|";
		this->contact[i].show();
		std::cout << std::endl;
	}
	deadSignalCheck();
	searchInformation();
}
