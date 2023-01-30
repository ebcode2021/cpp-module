/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:23:16 by eunson            #+#    #+#             */
/*   Updated: 2023/01/27 17:58:40 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	deadSignalCheck(void);

int	assertDarkestSecret(std::string &str)
{
	if (str.compare("I'm not a Robot"))
	{
		std::cout << "You are a Robot" << std::endl;
		return (0);
	}
	return (1);
}

int	assertPhoneNumber(std::string& str)
{
	if (str.length() == 0)
	{
		std::cout << "phoneNumber is essential information" << std::endl;
		return (0);
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == 0)
		{
			std::cout << "only use number!" << std::endl;
			return (0);
		}
	}
	return (1);
}

void	Contact::add(void)
{
	std::cout << "firstName? : ";
	std::getline(std::cin, this->firstName);
	deadSignalCheck();
	std::cout << "lastName? : ";
	std::getline(std::cin, this->lastName);
	deadSignalCheck();
	std::cout << "nickName? : ";
	std::getline(std::cin, this->nickName);
	deadSignalCheck();
	while (1)
	{
		std::cout << "phoneNumber?(only use number) : ";
		std::getline(std::cin, this->phoneNumber);
		if (assertPhoneNumber(this->phoneNumber))
			break;
		deadSignalCheck();
	}
	while (1)
	{
		std::cout << "Enter the sentence on the right [I'm not a Robot] : ";
		std::getline(std::cin, this->darkestSecret);
		if (assertDarkestSecret(this->darkestSecret))
			break;
		deadSignalCheck();
	}
}

void	Contact::show()
{
	std::string	output[3] = {firstName, lastName, nickName};

	for (int i = 0; i < 3; i++)
	{
		std::cout.width(10);
		if (output[i].length() > 10)
		{
			output[i] = output[i].replace(9, 10, ".");
			std::cout << output[i].substr(0, 10);
		}
		else
			std::cout << output[i];
		if (i < 2)
			std::cout << "|";
	}
}

void	Contact::showDetail()
{
	std::cout << "********* This is Information *********" << std::endl;
	std::cout << this->firstName << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->nickName << std::endl;
	std::cout << this->phoneNumber << std::endl;
	std::cout << this->darkestSecret << std::endl;
	std::cout << "***************************************" << std::endl; 
}