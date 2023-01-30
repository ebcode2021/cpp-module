/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:25:37 by eunson            #+#    #+#             */
/*   Updated: 2023/01/27 16:40:09 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	deadSignalCheck(void);

int main(void)
{
	int			idx = 0;
	PhoneBook 	phoneBook;

	while (1)
	{
		std::string str;
		std::cout << "Type Command [ADD | SEARCH | EXIT] : ";
		std::getline(std::cin, str);
		if (str.compare("ADD") == 0 || str.compare("add") == 0)
			phoneBook.add(idx++ % 8);
		else if (str.compare("SEARCH") == 0 || str.compare("search") == 0)
			phoneBook.search();
		else if (str.compare("EXIT") == 0 || str.compare("exit") == 0)
			break ;
		deadSignalCheck();
	}
	return (0);
}