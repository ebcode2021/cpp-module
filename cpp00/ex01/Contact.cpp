/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:23:16 by eunson            #+#    #+#             */
/*   Updated: 2023/01/26 20:08:59 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Contact::Contact()
// {
// 	std::cout << "Contact Constructor called" << std::endl;
// }

// Contact::~Contact()
// {
// 	std::cout << "Contact Destructor called" << std::endl;
// }

void	assertDarkestSecret(std::string &str)
{
	if (str.compare("I'm not a Robot"))
	{
		std::cout << "땡!" << std::endl;
		exit(1);
	}
}

void	assertPhoneNumber(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == 0)
		{
			std::cout << "only use number!" << std::endl;
			exit(1);
		}
	}
}

void	Contact::add(void)
{
	std::cout << "What's your firsName? : ";
	std::getline(std::cin, firstName);
	std::cout << "What's your lastName? : ";
	std::getline(std::cin, lastName);
	std::cout << "What's your nickName? : ";
	std::getline(std::cin, nickName);
	std::cout << "What's your phoneNumber? (only use number ex) 01012345678) : ";
	std::getline(std::cin, phoneNumber);
	assertPhoneNumber(phoneNumber);
	std::cout << "Type the sentence on the right [I'm not a Robot] : ";
	std::getline(std::cin, darkestSecret);
	assertDarkestSecret(darkestSecret);
}

void	Contact::show(Contact *con)
{
	int i = 0;

	for (int i = 0; i < 8; i++)
	{
		std::string first = con[i].firstName;
		std::string second = con[i].lastName;
		std::string third = con[i].nickName;
		std::string	output[3] = {first, second, third};

		std::cout.width(10);
		std::cout << i + 1;
		std::cout << "|";
		
		for (int j = 0; j < 3; j++)
		{
			std::cout.width(10);
			if (output[j].length() > 10)
			{
				output[j] = output[j].replace(9, 10, ".");
				std::cout << output[j].substr(0, 10);
			}
			else
				std::cout << output[j];
			if (j < 2)
				std::cout << "|";
		}
	
		std::cout << std::endl;
	}
}