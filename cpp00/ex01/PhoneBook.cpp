/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:17:43 by eunson            #+#    #+#             */
/*   Updated: 2023/01/26 19:41:17 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

#define WIDTH 10;

// PhoneBook::PhoneBook()
// {
// 	std::cout << "PhoneBook Constructor called" << std::endl;
// }

// PhoneBook::~PhoneBook()
// {
// 	std::cout << "PhoneBook Destructor called" << std::endl;
// }

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

void	PhoneBook::search(void)
{
	printHeader();
	contact->show(contact);
}
