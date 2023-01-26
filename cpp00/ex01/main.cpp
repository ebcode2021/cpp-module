/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:25:37 by eunson            #+#    #+#             */
/*   Updated: 2023/01/26 20:10:04 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	int			add_idx = 0;
	PhoneBook 	phoneBook;

	while (1)
	{
		std::string str;
		std::cout << "Type Cmd [ADD | SEARCH | EXIT] : ";
		std::getline(std::cin, str);
		if (str.compare("ADD") == 0)
			phoneBook.add(add_idx++ % 8);
		else if (str.compare("SEARCH") == 0)
			phoneBook.search();
		else if (str.compare("EXIT") == 0)
			break ;
		if (std::cin.eof())
			break ;
	}
	return (0);
}